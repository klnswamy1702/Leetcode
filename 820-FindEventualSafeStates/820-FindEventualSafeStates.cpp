// Last updated: 07/11/2025, 13:43:46
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revGraph(n);
        vector<int> indegree(n, 0);

        // Reverse the graph
        for (int u = 0; u < n; ++u) {
            for (int v : graph[u]) {
                revGraph[v].push_back(u);
                indegree[u]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> safe;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe.push_back(node);

            for (int neighbor : revGraph[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        sort(safe.begin(), safe.end());
        return safe;
    }
};

// class Solution {
// private:
//     bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathVis, vector<int>& safe) {
//         vis[node] = 1;
//         pathVis[node] = 1;

//         for (int neighbor : graph[node]) {
//             if (!vis[neighbor]) {
//                 if (!dfs(neighbor, graph, vis, pathVis, safe))
//                     return false;
//             } else if (pathVis[neighbor]) {
//                 return false;
//             }
//         }

//         pathVis[node] = 0;
//         safe[node] = 1;
//         return true;
//     }

// public:
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<int> vis(n, 0), pathVis(n, 0), safe(n, 0);

//         for (int i = 0; i < n; ++i) {
//             if (!vis[i])
//                 dfs(i, graph, vis, pathVis, safe);
//         }

//         vector<int> result;
//         for (int i = 0; i < n; ++i) {
//             if (safe[i]) result.push_back(i);
//         }
//         return result;
//     }
// };

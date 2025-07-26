class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& result) {
        visited[node] = 1;  // mark as visiting

        for (int neighbor : adj[node]) {
            if (visited[neighbor] == 0) {
                if (!dfs(neighbor, adj, visited, result))
                    return false;
            } else if (visited[neighbor] == 1) {
                return false;  // cycle detected
            }
        }

        visited[node] = 2;  // mark as visited
        result.push_back(node);  // post-order insertion
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);  // u -> v (take u before v)
        }

        vector<int> visited(numCourses, 0);
        vector<int> result;

        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] == 0) {
                if (!dfs(i, adj, visited, result))
                    return {};  // cycle detected
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

class Solution {
private:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathVis, vector<int>& safe) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (int neighbor : graph[node]) {
            if (!vis[neighbor]) {
                if (!dfs(neighbor, graph, vis, pathVis, safe))
                    return false;
            } else if (pathVis[neighbor]) {
                return false;
            }
        }

        pathVis[node] = 0;
        safe[node] = 1;
        return true;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0), pathVis(n, 0), safe(n, 0);

        for (int i = 0; i < n; ++i) {
            if (!vis[i])
                dfs(i, graph, vis, pathVis, safe);
        }

        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (safe[i]) result.push_back(i);
        }
        return result;
    }
};

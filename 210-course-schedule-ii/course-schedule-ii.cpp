class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> inDegree(numCourses, 0);

        // Step 1: Build the graph
        for (auto& pre : prerequisites) {
            int u = pre[1];  // prerequisite course
            int v = pre[0];  // course to take
            adj[u].push_back(v);
            inDegree[v]++;
        }

        // Step 2: Push all courses with no prerequisites
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // Step 3: BFS
        vector<int> topoOrder;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topoOrder.push_back(node);

            for (int neighbor : adj[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 4: Check if all courses are included
        if (topoOrder.size() == numCourses) {
            return topoOrder;
        }

        return {};  // cycle detected, not all courses can be completed
    }
};
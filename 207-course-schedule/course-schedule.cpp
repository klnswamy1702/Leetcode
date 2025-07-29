class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for (auto& it : prerequisites) {
            adj[it[1]].push_back(it[0]);  // course A depends on B → edge: B → A
        }

        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            for (int nbr : adj[i]) {
                indegree[nbr]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int count = 0;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            count++;

            for (int nbr : adj[node]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) q.push(nbr);
            }
        }

        return count == numCourses;
    }
};
// Last updated: 07/11/2025, 13:43:59
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Build adjacency list
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& edge : times) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
        }

        // Min-heap priority queue: {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [time, node] = pq.top(); pq.pop();

            for (auto& [nei, wt] : adj[node]) {
                if (time + wt < dist[nei]) {
                    dist[nei] = time + wt;
                    pq.push({dist[nei], nei});
                }
            }
        }

        int maxTime = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == 1e9) return -1;
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime;
    }
};
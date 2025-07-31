class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Step 1: Create adjacency list
        vector<pair<int, int>> adj[n];
        for (auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        // Step 2: Initialize min-heap, distance and ways arrays
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        int mod = 1e9 + 7;

        // Step 3: Start from node 0
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        // Step 4: Standard Dijkstra with path counting
        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            for (auto& [adjNode, wt] : adj[node]) {
                if (d + wt < dist[adjNode]) {
                    dist[adjNode] = d + wt;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode], adjNode});
                } else if (d + wt == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
        
    }
};
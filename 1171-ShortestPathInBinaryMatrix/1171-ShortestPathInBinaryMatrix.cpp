// Last updated: 07/11/2025, 13:42:56
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;

        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});
        grid[0][0] = 1; // mark visited by setting to non-zero

        vector<int> dx = {-1, -1, -1, 0, 1, 1, 1, 0};
        vector<int> dy = {-1, 0, 1, 1, 1, 0, -1, -1};

        while (!q.empty()) {
            auto [dist, cell] = q.front();
            q.pop();
            int r = cell.first, c = cell.second;

            if (r == n-1 && c == n-1) return dist;

            for (int i = 0; i < 8; ++i) {
                int nr = r + dx[i];
                int nc = c + dy[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                    q.push({dist + 1, {nr, nc}});
                    grid[nr][nc] = 1; // mark as visited
                }
            }
        }
        return -1;
        
    }
};
// Last updated: 07/11/2025, 13:43:08
class Solution {
    public int numEnclaves(int[][] grid) {
        Queue<int[]> q = new LinkedList<>();  // use int[] instead of Pair
        int n = grid.length; 
        int m = grid[0].length; 
        int vis[][] = new int[n][m];
        
        // traverse boundary elements
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 || j == 0 || i == n-1 || j == m-1) {
                    if(grid[i][j] == 1) {
                        q.add(new int[]{i, j});  // store coordinates as array
                        vis[i][j] = 1; 
                    }
                }
            }
        }
        
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1}; 
        
        while(!q.isEmpty()) {
            int[] cell = q.poll();  // dequeue
            int row = cell[0];
            int col = cell[1];
            
            // traverses all 4 directions
            for(int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i]; 
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                   && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    q.add(new int[]{nrow, ncol});
                    vis[nrow][ncol] = 1; 
                }
            }
        }
        
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && vis[i][j] == 0) 
                    cnt++; 
            }
        }
        return cnt;
    }
}

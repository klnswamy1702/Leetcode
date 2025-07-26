class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        board[row][col] = '#';  // mark safe 'O'

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; ++i) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, board);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();

        // Step 1: Mark all boundary-connected 'O's with '#'
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') dfs(0, j, board);
            if (board[m - 1][j] == 'O') dfs(m - 1, j, board);
        }

        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') dfs(i, 0, board);
            if (board[i][n - 1] == 'O') dfs(i, n - 1, board);
        }

        // Step 2: Flip unmarked 'O' to 'X', and '#' back to 'O'
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};

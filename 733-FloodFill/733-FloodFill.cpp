// Last updated: 07/11/2025, 13:44:02
class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& image,
             int newColor, int initialColor, int delRow[], int delCol[]) {
        
        image[row][col] = newColor;
        int m = image.size();
        int n = image[0].size();

        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                image[nrow][ncol] == initialColor) {
                dfs(nrow, ncol, image, newColor, initialColor, delRow, delCol);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];

        // Avoid infinite loop if color is same
        if (initialColor == color) return image;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        dfs(sr, sc, image, color, initialColor, delRow, delCol);
        return image;
    }
};

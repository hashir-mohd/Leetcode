using vi = vector<int>;
using vvi = vector<vector<int>>;
class Solution {
    void traversal(int row, int col, vvi& visited, vector<vector<int>>& grid,int color,int original) {
        visited[row][col] = 1;
        grid[row][col]=color;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for (int d = 0; d < 4; d++) {
            int nrow = row + dx[d], ncol = col + dy[d];
            if (nrow >= 0 && ncol >= 0 && nrow < grid.size() &&
                ncol < grid[0].size() && grid[nrow][ncol] == original &&
                visited[nrow][ncol] == 0) {
                traversal(nrow,ncol,visited,grid,color,original);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int original=image[sr][sc];
        vector<vector<int>> visited(n+1, vector<int>(n+1, 0));

        traversal(sr,sc,visited,image,color,original);

        return image;
    }
};
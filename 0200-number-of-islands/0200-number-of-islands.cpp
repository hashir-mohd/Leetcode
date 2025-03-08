using vi = vector<int>;
using vvi = vector<vector<int>>;

class Solution {
    void traversal(int row, int col, vvi& visited, vector<vector<char>>& grid) {
        visited[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nrow = row + dx[d], ncol = col + dy[d];
                if (nrow >= 0 && ncol >= 0 && nrow < grid.size() &&
                    ncol < grid[0].size() && grid[nrow][ncol] == '1' &&
                    visited[nrow][ncol] == 0) {
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        int islands = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] == 0 && grid[i][j]=='1') {
                    islands++;
                    traversal(i, j, visited, grid);
                }
            }
        }

        return islands;
    }
};
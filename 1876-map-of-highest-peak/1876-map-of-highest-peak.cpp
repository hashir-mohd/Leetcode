class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        // Directions for moving in the 4 cardinal directions
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        queue<pair<int, int>> q;

        // Initialize water cells with 0 and mark land cells as -1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    mat[i][j] = 0; // Water cells have height 0
                    q.push({i, j}); // Enqueue all water cells
                } else {
                    mat[i][j] = -1; // Mark land cells as unvisited
                }
            }
        }

        // Perform BFS to calculate the height of each land cell
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                // Process only unvisited land cells
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] == -1) {
                    mat[nx][ny] = mat[x][y] + 1; // Set height
                    q.push({nx, ny}); // Enqueue the updated cell
                }
            }
        }

        return mat;
    }
};

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==1){
            if(grid[0][0]==0)return 1;
            else return -1;
        }

        vector<int> dx = {-1, -1, -1, 0, 1, 1, 1, 0};
        vector<int> dy = {-1, 0, 1, 1, 1, 0, -1, -1};
        if (grid[0][0] == 1 || grid[n-1][n-1]==1)
            return -1;
        int dist = 1;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for (int d = 0; d < 8; d++) {
                    int nrow = row + dx[d], ncol = col + dy[d];
                    if(nrow==n-1 && ncol==n-1){
                        return dist+1;
                    }
                    if (nrow >= 0 && ncol >= 0 && nrow < grid.size() &&
                        ncol < grid[0].size() && grid[nrow][ncol] ==0 &&
                        visited[nrow][ncol] == 0) {
                        visited[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    // grid[i][j]=INT_MAX;
                    count++;
                }
            }
            if (count > 1) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1) {
                        grid[i][j] = INT_MAX;
                    }
                }
                res+=count;
            }
        }
        for (int i = 0; i < n; i++) {

            int count = 0;
            bool flag=false;
            for (int j = 0; j < m; j++) {
                if (grid[j][i] == 1) {
                    
                    count++;
                }
                if(grid[j][i]==INT_MAX){
                    flag=true;
                }
            }
            if (count > 1 || flag) {
                for (int j = 0; j < m; j++) {
                    if (grid[j][i] == 1) {
                        grid[j][i] = INT_MAX;
                    }
                }
                res+=count;
            }
        }
        return res;
    }
};
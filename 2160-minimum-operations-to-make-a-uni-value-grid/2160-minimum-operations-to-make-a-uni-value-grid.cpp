class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> a;
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                a.push_back(grid[i][j]);
            }
        }

        sort(a.begin(),a.end());
        int s=a.size();
        int operations=0;
        int midIdx=s/2;
        int target=a[midIdx];
        for(int i =0;i<s;i++){
            if(i==midIdx)continue;
            if((abs(target-a[i])%x) != 0)return -1;
            operations+=(abs(target-a[i])/x);
        }
        return operations;
    }
};
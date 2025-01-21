class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long n=grid[0].size();
        if(n==1) return 0;
        vector<long long>up(n,0);
        vector<long long>down(n,0);
        long long a=0;
        
        for(long long i=0;i<n;i++) {
            a+=grid[1][i];
            down[i]=a;
        }
        a=0;
        for(long long i=n-1;i>=0;i--) {
            a+=grid[0][i];
            up[i]=a;
        }
        long long res=0;
        long long ans= LLONG_MAX;
        for(long long i=1;i<n-1;i++) {
            res=max(up[i+1],down[i-1]);
            ans=min(ans,res);
        }
        long long ans1=min(up[1],down[n-2]);

        return min(ans,ans1);
    }
};
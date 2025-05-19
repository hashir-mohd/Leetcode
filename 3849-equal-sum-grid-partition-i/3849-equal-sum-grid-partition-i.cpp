class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        vector<long long> vert, hor;
        long long n= grid.size();
        long long m=grid[0].size();
        for(long long i=0;i<n;i++){
            long long sum=0;
            for(long long j =0;j<m;j++){
                sum+=grid[i][j];
            }
            vert.push_back(sum);
        }
        for(long long i=0;i<m;i++){
            long long sum=0;
            for(long long j =0;j<n;j++){
                sum+=grid[j][i];
            }
            hor.push_back(sum);
        }
        vector<long long> vertSuff(n),horSuff(m);
        long long sum=0;
        for(long long i=n-1;i>=0;i--){
            sum+=vert[i];
            vertSuff[i]=sum;
        }
        sum=0;
        for(long long i=m-1;i>=0;i--){
            sum+=hor[i];
            horSuff[i]=sum;
        }
        sum=0;
        for(long long i =0;i<n-1;i++){
            sum+=vert[i];
            if(sum==vertSuff[i+1])return true;
        }
        sum=0;
        for(long long i =0;i<m-1;i++){
            sum+=hor[i];
            if(sum==horSuff[i+1])return true;
        }
        return false;
    }
};
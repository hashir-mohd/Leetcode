class Solution {
public:
//[[1,3],[0,1]]
//[1,1,-1,0,-1]
//[1,2,1,1,0]
//1->0 , 2->1, 1->2
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        int m = requests.size();

        vector<int> diff(n);
        for(int i =0 ;i < m ;i++){
            int start=requests[i][0];
            int end= requests[i][1];
            diff[start]++;
            if(end<n-1){
                diff[end+1]--;
            }
            
        }
        for(int i=1;i<n;i++) {
            diff[i]+=diff[i-1];
        }
        sort(nums.begin(),nums.end());
        sort(diff.begin(),diff.end());
        int j=n-1;
        int ans=0;
        int mod=1e9+7;
        for(int i=diff.size()-1;i>=0;i--) {
            ans=(ans+1LL*nums[j]*diff[i])%mod;
            j--;
            if(diff[i]==0) {
                break;
            }
        }
        return ans;


    }
};
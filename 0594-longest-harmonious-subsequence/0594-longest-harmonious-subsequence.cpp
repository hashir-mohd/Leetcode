class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> mpp;
        int n = nums.size();
        for(int i =0 ;i < n;i++){
            mpp[nums[i]]++;
        }
        int ans=0;
        for(auto [key,freq]:mpp){
            int next=key+1;
            if(mpp.find(next)!=mpp.end()){
                ans=max(ans,freq+mpp[key+1]);
            }

            
        }
        return ans;

    }
};
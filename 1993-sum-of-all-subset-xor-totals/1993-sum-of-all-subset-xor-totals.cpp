class Solution {
    void helper(vector<int>&nums,int &ans,int i,int xorr){
        if(i>=nums.size()){
            ans+=xorr;
            return;
        }
        
        helper(nums,ans,i+1,xorr);
        xorr^=nums[i];
        helper(nums,ans,i+1,xorr);
    }
public:
    int subsetXORSum(vector<int>& nums) {
       int ans=0;
       int xorr=0;
       helper(nums,ans,0,xorr);
       return ans;
    }
};
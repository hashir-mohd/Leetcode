class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int res=1;
        int n = nums.size();
        int onesBits=nums[0];
        int left=0;
        int right=1;
        while(right<n){
            if((nums[right] & onesBits)==0){
                onesBits |= nums[right];
                res=max(res,right-left+1);
                right++;
                
            }else{
                onesBits^=nums[left];
                left++;
            }
        }
        return res;
    }
};
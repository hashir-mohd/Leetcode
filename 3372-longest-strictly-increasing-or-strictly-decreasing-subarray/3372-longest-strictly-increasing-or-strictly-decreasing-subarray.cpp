class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int res=1;
        int count=1;
        for(int i =1 ;i < nums.size();i++){
            if(nums[i]>nums[i-1]) count++;
            else{
                count=1;
            }
            res=max(count,res);
        }
         count=1;
        for(int i =1 ;i < nums.size();i++){
            if(nums[i]<nums[i-1]) count++;
            else{
                count=1;
            }
            res=max(count,res);
        }
        return res;
    }
};
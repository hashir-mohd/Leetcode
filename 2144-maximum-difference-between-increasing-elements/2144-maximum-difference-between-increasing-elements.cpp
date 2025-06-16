class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int smallest=nums[0];
        int res=0;
        int n = nums.size();
        for(int i =1;i<n;i++){
            
            if(nums[i]<smallest){
                smallest=nums[i];
                continue;
            }
            if(nums[i]>smallest){
                res=max(res,nums[i]-smallest);
            }
            
            
        }
        if(res==0){
            return -1;
        }
        return res;
    }
};
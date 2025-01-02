class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int output=0;
        int left=0;
        long long curr=0;
        for(int right= 0; right<nums.size();right++){
            long long target = nums[right];
            curr+=target;
            while((right-left+1)*target-curr>k){
                curr-=nums[left];
                left++;
            }
            output=max(output,right-left+1);
        }
        return output;
    }
};
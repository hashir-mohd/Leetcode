class Solution {
public:
    int helper(vector<int>&nums, int k){
        int res=0;
        int n= nums.size();
        int right=0;
        int left= 0;
        unordered_map<int,int> freq;
        while(right<n){
            freq[nums[right]]++;

            while(freq.size()>k){
                freq[nums[left]]--;
                if(freq[nums[left]]==0){
                    freq.erase(nums[left]);
                }
                left++;
            }
            res+=(right-left+1);
            right++;
        }
        return res;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums,k)- helper(nums,k-1);
    }
};
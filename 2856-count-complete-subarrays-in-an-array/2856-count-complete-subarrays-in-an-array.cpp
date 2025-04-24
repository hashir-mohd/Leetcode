class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int> cnt;
        unordered_set<int> distinct(nums.begin(),nums.end());
        int ans=0;
        int right=0;
        int k = distinct.size();
        int n = nums.size();
        for(int left=0;left<n;left++){
            if(left>0){
                cnt[nums[left-1]]--;
                if(cnt[nums[left-1]]==0){
                    cnt.erase(nums[left-1]);
                }
            }
            while(right<n && cnt.size()<k){
                cnt[nums[right]]++;
                right++;
            }
            if(cnt.size()==k){
                ans+=(n-right+1);
            }
        }
        return ans;
    }

};
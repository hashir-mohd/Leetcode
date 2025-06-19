class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int subs=1;
        int rec = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] - rec > k) {
                subs++;
                rec = nums[i];
            }
        }
        return subs;

    }
};
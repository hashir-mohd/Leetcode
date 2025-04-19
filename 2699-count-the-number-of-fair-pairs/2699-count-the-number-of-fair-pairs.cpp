class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return func(nums, lower) - func(nums, upper+1);
    }

private:
    long long func(vector<int>& nums, int value) {
        int left = 0, right = nums.size() - 1;
        long long result = 0;
        int n = nums.size();
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (nums[left] + nums[right] >= value) {
                result += (right - left);  // all pairs (left, left+1)...(left, right)
                right--;
            } else {
                left++;
            }
        }
        return result;
    }
};
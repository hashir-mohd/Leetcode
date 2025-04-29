class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxElement = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        int right = 0;
        int countMax = 0;
        long long ans = 0;

        for (int left = 0; left < n; left++) {
            // Move right to maintain countMax <= k
            while (right < n && countMax < k) {
                if (nums[right] == maxElement) {
                    countMax++;
                }
                right++;
            }

            if (countMax == k) {
                // From right-1 to n-1 are valid subarray ends
                ans += (n - right + 1);
            }

            // Slide left forward
            if (nums[left] == maxElement) {
                countMax--;
            }
        }

        return ans;
    }
};

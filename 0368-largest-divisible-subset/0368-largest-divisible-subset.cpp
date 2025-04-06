class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return {};
        
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);    // dp[i] = length of largest divisible subset ending with nums[i]
        vector<int> prev(n, -1); // to track previous index for backtracking
        
        int maxSize = 1, maxIndex = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > maxSize) {
                maxSize = dp[i];
                maxIndex = i;
            }
        }
        
        // Backtrack to build the largest divisible subset
        vector<int> result;
        while (maxIndex != -1) {
            result.push_back(nums[maxIndex]);
            maxIndex = prev[maxIndex];
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
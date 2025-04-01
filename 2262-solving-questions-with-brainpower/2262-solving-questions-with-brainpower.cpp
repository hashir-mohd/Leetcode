class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0); // DP array with one extra element
        long long best = 0; // Running maximum of points obtained so far

        for (int i = 0; i < n; i++) {
            best = max(best, dp[i]); // Ensure best score is carried forward
            int nextIndex = i + questions[i][1] + 1;

            // If we solve this question, update future DP values
            if (nextIndex < n) {
                dp[nextIndex] = max(dp[nextIndex], best + questions[i][0]);
            }

            // Also update the current position with the best score
            dp[i] = max(dp[i], best + questions[i][0]);
        }

        return *max_element(dp.begin(), dp.end()); // Maximum points achievable
    }
};

class Solution {
public:
    long long solve(int idx, vector<vector<int>>& rides, vector<long long>& dp) {
        if (idx == rides.size()) return 0;
        if (dp[idx] != -1) return dp[idx];

        long long notPick = solve(idx + 1, rides, dp);

        int start = rides[idx][0];
        int end = rides[idx][1];
        int tip = rides[idx][2];

        int left = idx + 1, right = rides.size() - 1, next = rides.size();
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (rides[mid][0] >= end) {
                next = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        long long pick = (end - start + tip) + solve(next, rides, dp);

        return dp[idx] = max(notPick, pick);
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end());
        vector<long long> dp(rides.size(), -1);
        return solve(0, rides, dp);
    }
};

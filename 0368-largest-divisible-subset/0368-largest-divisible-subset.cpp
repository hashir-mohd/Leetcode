class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // dp[i][j] = max subset length starting at i, with prev index j-1
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        vector<vector<int>> path(n, vector<int>(n + 1, -1)); // for reconstruction

        // Recursive function with memoization
        function<int(int, int)> dfs = [&](int curr, int prev) -> int {
            if (curr == n) return 0;
            if (dp[curr][prev + 1] != -1) return dp[curr][prev + 1];

            int take = 0, notTake = 0;

            if (prev == -1 || nums[curr] % nums[prev] == 0) {
                take = 1 + dfs(curr + 1, curr);
            }
            notTake = dfs(curr + 1, prev);

            if (take > notTake) {
                path[curr][prev + 1] = 1; // take this element
                return dp[curr][prev + 1] = take;
            } else {
                path[curr][prev + 1] = 0; // skip this element
                return dp[curr][prev + 1] = notTake;
            }
        };

        dfs(0, -1); // start from index 0, with no previous element

        // Reconstruct the subset using the path matrix
        vector<int> subset;
        int curr = 0, prev = -1;
        while (curr < n) {
            if (path[curr][prev + 1] == 1) {
                subset.push_back(nums[curr]);
                prev = curr;
            }
            curr++;
        }

        return subset;
    }
};

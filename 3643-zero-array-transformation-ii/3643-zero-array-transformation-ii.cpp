class Solution {
    bool solve(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);

        
        for (int i = 0; i < k; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];

            diff[l] += val; 
            if (r + 1 < n) {
                diff[r + 1] -= val;  // Restore value after range
            }
        }

        // Apply the difference array to get the modified nums
        vector<int> modified = nums;
        int running_sum = 0;

        for (int i = 0; i < n; i++) {
            running_sum += diff[i];
            modified[i] -= running_sum;
        }

        // Check if the entire array is ≤ 0
        for (int i = 0; i < n; i++) {
            if (modified[i] > 0) return false;
        }
        return true;
    }

public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int left = 0, right = queries.size(), ans = -1;

        if (*max_element(nums.begin(), nums.end()) == 0) return 0;

        // Binary search for the minimum k
        while (left <= right) {
            int k = left + (right - left) / 2;

            if (solve(nums, queries, k)) {
                ans = k;  // Update answer to minimum k that works
                right = k - 1;  // Try smaller k
            } else {
                left = k + 1;  // Increase k if we cannot make the array zero
            }
        }

        return ans;
    }
};

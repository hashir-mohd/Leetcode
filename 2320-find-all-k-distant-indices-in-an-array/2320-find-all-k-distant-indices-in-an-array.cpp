class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> diffarr(n + 1, 0);
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {
                int l = max(0, i - k);
                int r = min(n, i + k + 1);
                diffarr[l]++;
                if (r < n)
                    diffarr[r]--;
            }
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += diffarr[i];
            if (sum > 0) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
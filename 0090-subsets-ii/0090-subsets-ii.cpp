using vi = vector<int>;
using vvi = vector<vector<int>>;

class Solution {
public:
    void subset(vvi& res, vi curr, vi& nums, int idx) {
        res.push_back(curr);
        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i - 1] == nums[i])
                continue;
            // not take
            //subset(res, curr, nums, i + 1);
            // take
            curr.push_back(nums[i]);
            subset(res, curr, nums, i + 1);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vvi res;
        vi curr;
        int n = nums.size();
        subset(res, curr, nums, 0);
        return res;
    }
};
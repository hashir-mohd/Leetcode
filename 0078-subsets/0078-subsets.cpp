using vvi=vector<vector<int>>;
using vi =vector<int>;
class Solution {
public:
    void subset(vvi & res,vi curr,vi nums,int n){
        if(n<0){
            res.push_back(curr);
            return;
        }
        // not take
        subset(res,curr,nums,n-1);
        //take
        curr.push_back(nums[n]);
        subset(res,curr,nums,n-1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        int n =nums.size();
        subset(res,curr,nums,n-1);
        return res;
    }
};
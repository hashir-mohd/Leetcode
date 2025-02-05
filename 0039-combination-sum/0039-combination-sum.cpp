using vi = vector<int>;           
using vvi = vector<vector<int>>; 

class Solution {
public:
    void helper(vvi &res,vi curr,vi &nums,int target,int n){
        if(target<0 || n<0){
            return;
        }
        if(target==0){
            res.push_back(curr);
            return;
        }
        //not take
        helper(res,curr,nums,target,n-1);
        //take
        curr.push_back(nums[n]);
        helper(res,curr,nums,target-nums[n],n);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        vvi res;
        vi curr;
        helper(res,curr,nums,target,n-1);
        return res;
    }
};
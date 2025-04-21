class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mapp;
        vector <int> ans;
        for(int i =0 ; i <nums.size() ; i++){
            int num = nums[i];
            int moreNeeded = target -num;
            if(mapp.find(moreNeeded) != mapp.end()){
                // return {mapp[moreNeeded],i};
                ans.push_back(mapp[moreNeeded]);
                ans.push_back(i);
                return ans;
            }
            mapp[num] =i;
        }
        return ans;
    }
};
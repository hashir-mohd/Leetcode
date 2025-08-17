#define ll long long
class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        ll prefix = 0;
        ll totalRemaining = 0;
        map<int, ll> mpp;
        mpp[0] = 0; // handles subarrays starting at index 0

        for(int num : nums){
            prefix += num;
            totalRemaining += num;

            int mod = prefix % k;
            if(mpp.find(mod) != mpp.end()){
                // we can delete subarray from last index with same mod + 1 to current
                totalRemaining = min(totalRemaining, mpp[mod]);
            }

            // update the map with current minimum remaining sum for this mod
            mpp[mod] = totalRemaining;
        }

        return totalRemaining;
    }
};

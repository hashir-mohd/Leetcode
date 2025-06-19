class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int maxx = INT_MIN;
        for (auto& it : nums) {
            maxx = max(maxx, it);
        }
        vector<int> freq(maxx + 1);
        for (auto& x : nums) {
            freq[x]++;
        }
        int rec=-100005;
        int ans=0;
        for (int i = 0; i <= maxx; i++) {
            if(freq[i]>0 && i-rec>k){
                rec=i;
                ans++;
            }
        }
        return ans;
    }
};
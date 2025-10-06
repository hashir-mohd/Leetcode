class Solution {
public:
    vector<int> computeSPF(int maxNum) {
         vector<int> spf(maxNum + 1);
        for (int i = 0; i <= maxNum; i++) spf[i] = i;
        for (int i = 2; i * i <= maxNum; i++) {
            if (spf[i] == i) { // i is prime
                for (int j = i * i; j <= maxNum; j += i) {
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }
        return spf;
    }

    int minOperations(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int n = nums.size();
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<int> spf = computeSPF(maxNum);

        int count=0;


        for(int i = nums.size()-2;i>=0;i--){
            if(nums[i]<=nums[i+1]){
                continue;
            }
            else{
                while(nums[i]>nums[i+1]){
                    if( spf[nums[i]]==nums[i]) {
                        return -1;
                    }
                    nums[i]=spf[nums[i]];
                    count++;
                }
            }
        }
        return count;
    }
};
class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        int n=100;
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int p = 2; p * p <= n; ++p) {
            if (isPrime[p]) {
                for (int multiple = p * p; multiple <= n; multiple += p) {
                    isPrime[multiple] = false;
                }
            }
        }

        vector<int> freq(101,0);
        for(int i =0;i < nums.size();i++){
            freq[nums[i]]++;
        }

        for(int i=0;i< freq.size();i++){
            if(isPrime[freq[i]]){
                return true;
            }
        }
        return false;

    }
};
class Solution {
    int mod= 1e9+7;
private:
    int countSubsetsHelper(int idx, int target, vector<int> &arr, vector<vector<int>> &dp) {
    if (target == 0) return 1;

    if (idx < 0) return 0;
    if (dp[idx][target] != -1) return dp[idx][target];

    
    int notTake = countSubsetsHelper(idx - 1, target, arr, dp);

    
    int take = 0;
    if (arr[idx] <= target) {
        take = countSubsetsHelper(idx - 1, target - arr[idx], arr, dp);
    }

    return dp[idx][target] = (take + notTake)%mod;
}
public:
    int numberOfWays(int n, int x) {
        vector<int> arr;
        for(int i =1 ;i <=n ;i++){
            if(pow(i,x)>n) break;
            arr.push_back(pow(i,x));
        }
        int a = arr.size();
        vector<vector<int>> dp(a, vector<int>(n + 1, -1));
        return countSubsetsHelper(a - 1, n, arr, dp);
    }
};
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans=0;
        for(int i =0 ;i <=min(n,limit); i++){
            int lower = max(0, n - i - limit);
            int upper = min(limit, n - i);
            ans += max(upper - lower + 1, 0);
        }
        return ans;
    }
};
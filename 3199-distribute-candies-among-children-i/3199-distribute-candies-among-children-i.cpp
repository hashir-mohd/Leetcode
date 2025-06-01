class Solution {
public:
    int distributeCandies(int n, int limit) {
        int ans=0;
        for(int i =0 ;i <=min(n,limit); i++){
            ans+=max(min(limit, n - i) - max(0, n - i - limit) + 1, 0);
        }
        return ans;
    }
};
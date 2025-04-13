class Solution {
public:
    int mod=1e9+7;

    int countGoodNumbers(long long n) {
        int  output=0;
        long long evens=(n+1)/2;
        long long odds= n/2;
        output=(power(5,evens)*power(4,odds))%mod;
        return output;

    }

    long long power(long long base, long long exp){
        long long res=1;
        while(exp>0){
            if(exp%2==1){
                res=(res*base)%mod;
            }
            base=(base*base)%mod;
            exp/=2;
        }
        return res;
    }
};
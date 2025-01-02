class Solution {
public:
    int reverse(int y) {
                if (y == INT_MIN) return 0; // Edge case: cannot negate INT_MIN safely

        bool pos= y>=0;
        long long x=abs(y);
        long long res =0;
        while(x!=0){
            int lastDigit = x%10;
            x/=10;
            res=res*10 + lastDigit;
        }
        cout << pos<< endl;
        if(pos==0){
            res=res*(-1);
        }
        if(res>INT_MAX || res<INT_MIN) return 0;
        return res;

    }
};
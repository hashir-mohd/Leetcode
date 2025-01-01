class Solution {
public:
    int maxScore(string s) {
        int ones = 0;
        int zeroes = 0;
        int res=0;
        for(auto ch : s){
            if(ch=='1') ones++;
        }
        for(int i =0 ; i<s.length()-1;i++){
            if(s[i]=='0') zeroes++;
            if(s[i]=='1') ones--;
            res=max(res,(zeroes+ones));
        }
        return res;
    }
};
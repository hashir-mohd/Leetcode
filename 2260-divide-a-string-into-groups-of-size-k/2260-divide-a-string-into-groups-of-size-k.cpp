class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        int n = s.size();
        for(int i=0;i<n;i+=k){
            string sub= s.substr(i,k);
            res.push_back(sub);
        }
        int len=res.size();
        string last=res[len-1];
        while(last.size()<k){
            last+=fill;
        }
        res[len-1]=last;
        return res;
    }
};
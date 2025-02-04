class Solution {
public:
    void generator(vector<string> &res, int open, int close, int n,string comb){
        if(close==n){
            res.push_back(comb);
            return;
        }
        
        if(open<n){
            generator(res,open+1,close,n,comb+"(");
        }
        if(close<open){
            generator(res,open,close+1,n,comb+")");
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generator(res,0,0,n,"");
        return res;
        
    }
};
class Solution {
private:
    vector<vector<int>> memo;

    bool isPal(int i, int j,string &s){
        if(i>j) return true;
        if(memo[i][j]!= -1)return memo[i][j];
        if(s[i]==s[j]){
            if(isPal(i+1,j-1,s)){
                memo[i][j]=1;
                return true;
            }
        }
        memo[i][j]=0;
        return false;
    }


public:
    int countSubstrings(string s) {
        int n =s.size();
        int count=0;
        memo.assign(n,vector<int>(n,-1));
        for(int i =0 ;i < n ; i++){
            for(int j =i ;j < n; j++){
                if(isPal(i,j,s)){
                    count++;
                }
            }
        }
        return count;
    }
};
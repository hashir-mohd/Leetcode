class Solution {
    void func(int d,int i, int j, vector<vector<int>> & res,int &curr){
        if(d==1){
            res[i][j]=curr;
            curr++;
            return;
        }
        func(d/2,i,j+d/2,res,curr);
        func(d/2,i+d/2,j+d/2,res,curr);
        func(d/2,i+d/2,j,res,curr);
        func(d/2,i,j,res,curr);
        return;
    }

public:
    vector<vector<int>> specialGrid(int n) {
        int d=pow(2,n);
        vector<vector<int>> res(d,vector<int>(d,0));
        if(n==0)return res;
        int curr=0;
        func(d,0,0,res,curr);
        return res;
    }
};
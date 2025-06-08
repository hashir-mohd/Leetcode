class Solution {
    void f(int i , vector<int>&res, int n){
        if(i>n)return;
        res.push_back(i);
        for(int j=0;j<=9;j++){
            f(i*10+j,res,n);
        }   
        return;
    }
public:

    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int i=1;i<=9;i++){
            f(i,res,n);
        }
        return res;
    }
};
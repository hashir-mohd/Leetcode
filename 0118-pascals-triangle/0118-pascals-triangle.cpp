class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> curr;
        curr.push_back(1);
        res.push_back(curr);
        vector<int> prev= curr;
        if(numRows==1){
            return res;
        }
        // res.push_back({1,1});
        // if(numRows==2){
        //     return res;
        // }
        for(int i =1 ;i < numRows;i++){
            vector<int> temp;
            temp.push_back(1);
            // vector<int> prev= res[res.size()-1];
            for(int i =1 ;i < prev.size();i++){
                temp.push_back(prev[i]+prev[i-1]);
            }
            temp.push_back(1);
            res.push_back(temp);
            prev=temp;
        }
        return res;
    }
};
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int ans=0 ;
        for (int i =0 ;i < derived.size();i++){
            ans=ans^derived[i];
        }
        return ans==0?true:false;
    }
};
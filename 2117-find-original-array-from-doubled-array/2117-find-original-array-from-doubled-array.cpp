class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        vector<int> res;
        if(n&1){
            return res;
        }
        unordered_map<int,int>mp;
        sort(changed.begin(),changed.end());
        for(int i= 0; i< n ;i++){
            mp[changed[i]]++;
        }
        for(int i =0 ;i <n ;i++){
            if(mp[changed[i]]==0){
                continue;
            }
            mp[changed[i]]--;
            if(mp[changed[i]*2]==0){
                vector<int> temp;
                return temp;
            }
            else{
                mp[changed[i]*2]--;
            }
            res.push_back(changed[i]);
        }
        return res;
    }
};
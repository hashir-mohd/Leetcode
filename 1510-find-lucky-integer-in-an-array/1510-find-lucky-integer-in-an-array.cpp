class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> freq(501,0);
        int res=-1;
        for(auto &it:arr){
            freq[it]++;
            
        }
        for(int i =0 ;i < arr.size();i++){
            if(freq[arr[i]]==arr[i]){
                res=max(res,arr[i]);
            }
        }
        return res;
    }
};
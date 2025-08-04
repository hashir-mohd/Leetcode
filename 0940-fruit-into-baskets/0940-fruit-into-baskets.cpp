class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int i=0,j=0;
        int n = arr.size();
        int ans=0;
        unordered_map <int, int> m;
        while(j<n){
            m[arr[j]]++;
            if(m.size()>2){
                m[arr[i]]--;
                if(m[arr[i]]==0){
                    m.erase(arr[i]);
                }
                i++;
            }
            ans= max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};
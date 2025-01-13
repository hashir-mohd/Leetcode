class Solution {
public:
    int minimumLength(string s) {
        int ans=0;
        vector<int> freq(26,0);
        for(auto ch:s){
            freq[ch-'a']++;
        }
        for(int i = 0; i<freq.size();i++ ){
            if(freq[i]==0) continue;
            if(freq[i]%2==0)ans+=2;
            if(freq[i]%2==1)ans++;
        }
        return ans;
    }
};
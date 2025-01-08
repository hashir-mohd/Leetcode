class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int ans=0;
        for(int i =0 ;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(words[i].size()>words[j].size())continue;
                string pre=words[j].substr(0,words[i].size());
                string suf=words[j].substr(words[j].size() -words[i].size());
                if(pre==words[i] && suf==words[i])ans++;
            }
        }
        return ans;
    }
};
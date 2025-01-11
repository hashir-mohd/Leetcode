class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k==s.size()) return true;
        if(k>s.size()) return false;
        unordered_map <char,int> freq;
        for(auto ch : s){
            freq[ch]++;
        }
        int count=0;
        for(auto ch : freq){
            if(ch.second %2 ==1)count++;
        }
        return count<=k;

    }
};
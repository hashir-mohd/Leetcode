class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> letters;
        for(char c:s){
            letters.insert(c);
        }
        int ans=0;
        for(char letter:letters){
            int first=-1;
            int last=0;
            for(int i =0 ; i< s.size();i++){
                if(s[i]==letter){
                    if(first==-1){
                        first=i;
                    }
                    last=i;
                }
            }
            unordered_set<char> between;
            for(int i = first+1; i<last ;i++){
                between.insert(s[i]);
            }

            ans+=between.size();
        }
        return ans;
    }
};
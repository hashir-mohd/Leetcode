class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size(), ans=0;
        for(char c='A'; c<='Z'; c++){
            int i=0, j=0, count=0;
            while(j<n){
                if(s[j]!=c){
                    count++;
                }
                while(count>k){
                    
                    if(s[i]!=c) count--;
                    i++;
                }
                ans=max(ans,j-i+1);
                j++;
            }
            ans=max(ans,j-i);
        }

        return ans;
    }
};
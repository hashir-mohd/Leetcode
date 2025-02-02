class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256,0);
        
        int i=0,j=0;
        int n =s.size();
        if(n==0) return 0;
        if(n==1) return 1;
        int res=0;
        while(i<n &&j<n){
            char ch = s[i];
            if(ch)
            if(freq[ch-'\0']==0){
                freq[ch-'\0']++;
                // res++;
                res=max(res,i-j+1);
                i++;
                
            }
            else{
                freq[s[j]-'\0']--;
                j++;
            }
            
        }
        return res;
    }
};
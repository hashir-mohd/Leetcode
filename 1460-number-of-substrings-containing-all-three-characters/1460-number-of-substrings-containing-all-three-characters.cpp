class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int count=0, l=0;
        vector<int>lastSeen = {-1,-1,-1};
        for(int r=0; r<n; r++){
            lastSeen[s[r]-'a'] = r;
            // if(lastSeen[0]!=-1 && lastSeen[1]!=-1 && lastSeen[2]!=-1){
                int mini = min(lastSeen[0],min(lastSeen[1],lastSeen[2]));
                count += 1+mini;
            // }
        }
        return count;
        
    }
};
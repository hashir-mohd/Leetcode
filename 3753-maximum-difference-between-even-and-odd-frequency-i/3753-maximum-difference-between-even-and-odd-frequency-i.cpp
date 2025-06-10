class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>mpp;
        int maxOdd=0;
        int minEven=INT_MAX;
        for(auto &ch:s){
            mpp[ch]++;
        }

        for(auto [ch,freq]:mpp){
            if(mpp[ch]%2==1 && mpp[ch]>maxOdd){
                maxOdd=mpp[ch];
            }
            if(mpp[ch]%2==0 && mpp[ch]<minEven){
                minEven=mpp[ch];
            }
        }
        return maxOdd-minEven;

    }
};
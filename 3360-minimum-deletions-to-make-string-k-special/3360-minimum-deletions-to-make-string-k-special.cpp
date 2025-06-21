class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n = word.size();
        if(k>=n-2)return 0;
        unordered_map<char,int> mpp;
        for(auto &it:word){
            mpp[it]++;
        }
        vector<int> freq;
        for(auto &[ch,fre]:mpp){
            freq.push_back(fre);
        }
        sort(freq.begin(),freq.end());
        int res=INT_MAX;
        for(int i =0;i <= freq[freq.size()-1];i++){
            int currStart= i;
            int currEnd= currStart+k;
            int curr=0;
            for(int i =0;i < freq.size();i++){
                if(freq[i]<currStart){
                    curr+=(freq[i]);
                }else if(freq[i]>currEnd){
                    curr+=(freq[i]-currEnd);
                }
            }
            res=min(res,curr);
        }
        return res;
    }
};
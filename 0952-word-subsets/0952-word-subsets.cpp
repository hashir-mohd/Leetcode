class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char,int>maxFreq;
        for(auto b : words2){
            for(int i =0 ;i <26;i++){
                int count = std::count(b.begin(),b.end(),'a'+i);
                if(maxFreq['a'+i]<count || maxFreq.find('a'+i)==maxFreq.end()){
                    maxFreq['a'+i]=count;
                }
            }
        }
        vector<string> ans;
        for(auto a:words1){
            unordered_map<char,int>freq;
            for(int i =0 ;i <26;i++){
                int count = std::count(a.begin(),a.end(),'a'+i);
                if(freq['a'+i]<count || freq.find('a'+i)==freq.end()){
                    freq['a'+i]=count;
                }
            }
            bool flag=true;
            for(auto& pair:freq){
                if(maxFreq[pair.first]>pair.second){
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans.push_back(a);
            }
        }
        return ans;
    }
};
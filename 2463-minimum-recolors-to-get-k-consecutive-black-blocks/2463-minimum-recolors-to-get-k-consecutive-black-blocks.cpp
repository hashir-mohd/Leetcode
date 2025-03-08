class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        vector<int> prefix;
        int n =blocks.size();
        int whites=0;
        for(auto &color:blocks){
            if(color=='W'){
                whites++;
            }
            prefix.push_back(whites);
        }
        int left=0;
        int right=k-1;
        int res=prefix[right];
        left++;
        right++;

        while(right<n){
            
            res=min(res,prefix[right]-prefix[left-1]);
            left++;
            right++;
        }
        return res;
    }
};
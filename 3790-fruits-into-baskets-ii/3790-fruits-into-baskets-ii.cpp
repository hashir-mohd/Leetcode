class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        vector<int> filled(n,0);

        for(int fruit=0;fruit<n;fruit++){
            for(int basket=0;basket<n;basket++){
                if(filled[basket]==0 && baskets[basket]>=fruits[fruit]){
                    filled[basket]=1;
                    break;
                }
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            if(filled[i]==0)res++;
        }
        return res;
    }
};
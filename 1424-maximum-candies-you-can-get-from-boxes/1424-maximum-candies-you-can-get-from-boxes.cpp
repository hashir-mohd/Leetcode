class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int ans=0;
        queue<int>q;
        unordered_set<int> boxes;
        vector<int> pushed (status.size(),0);

        for(int i =0;i< initialBoxes.size();i++){
            int boxNumber=initialBoxes[i];
            if(status[boxNumber]==1){
                if(!pushed[boxNumber]){
                    q.push(boxNumber);
                    pushed[boxNumber]=1;
                }
                
            }
            else boxes.insert(initialBoxes[i]);
        }

        while(!q.empty()){
            int box=q.front();
            q.pop();
            ans+=candies[box];
            for(auto &it:keys[box]){
                if(boxes.find(it)!=boxes.end()){
                    if(!pushed[it]){
                    q.push(it);
                    pushed[it]=1;
                }
                }else{
                    status[it]=1;
                }
            }
            for(auto &it:containedBoxes[box]){
                if(status[it]){
                    if(!pushed[it]){
                    q.push(it);
                    pushed[it]=1;
                }
                }else{
                    boxes.insert(it);
                }
            }
        }
        return ans;

    }
};
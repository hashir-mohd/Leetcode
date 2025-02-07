class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> colorMap;
        unordered_map<int,int> colorFreq;
        vector<int> res;
        for(auto query:queries){
            int ball= query[0];
            int color=query[1];

            if(colorMap.find(ball)!= colorMap.end()){
                int oldColor= colorMap[ball];
                if(--colorFreq[oldColor]==0){
                    colorFreq.erase(oldColor);
                }
            }
            colorMap[ball]=color;
            colorFreq[color]++;

            res.push_back(colorFreq.size());
        }
        return res;
    }
};
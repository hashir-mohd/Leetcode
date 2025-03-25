class Solution {
    bool helper(vector<pair<int,int>>&interval,int n){
        int cuts=0;
        int m = interval.size();
        int curr=interval[0].second;
        for(int i =1 ;i <m;i++){
            int start=interval[i].first;
            int end=interval[i].second;
            if(start>=curr){
                cuts++;
                if(cuts>=2)return true;
            }
            curr=max(end,curr);
        }
        return cuts>=2;
    }

public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int,int>> horizontal;
        vector<pair<int,int>> vertical;
        int m= rectangles.size();
        for(auto &it:rectangles){
            horizontal.push_back({it[0],it[2]});
            vertical.push_back({it[1],it[3]});
        }
        sort(horizontal.begin(),horizontal.end());
        sort(vertical.begin(),vertical.end());

        return helper(horizontal,n) || helper(vertical,n);

    }
};
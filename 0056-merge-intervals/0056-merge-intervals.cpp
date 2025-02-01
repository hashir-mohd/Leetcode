class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int start= intervals[0][0];
        int end= intervals[0][1];
        vector<vector<int>> res;
        for(int i =1 ;i < intervals.size();i++){
            vector<int> ans;
            int begin= intervals[i][0];
            int last= intervals[i][1];
            if(begin>end){
                ans.push_back(start);
                ans.push_back(end);
                res.push_back(ans);
                start= begin;
                end= last;
            }
            else{
                end=max(end,last);
            }

        }
                res.push_back({start, end});

        return res;

    }
};
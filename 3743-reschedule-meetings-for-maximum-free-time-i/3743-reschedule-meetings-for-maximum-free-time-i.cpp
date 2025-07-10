class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
    vector<int> gaps;
    int n = startTime.size();
    gaps.push_back(startTime[0]-0);
    for(int i =1 ; i< n; i++){
        gaps.push_back(startTime[i]-endTime[i-1]);
    }
    gaps.push_back(eventTime-endTime[n-1]);
    vector<int> prefix;
    prefix.push_back(0);
    prefix.push_back(gaps[0]);
    
    for(int i =1;i< gaps.size();i++){
        prefix.push_back(prefix[i]+gaps[i]);
    }
    int res=0;
    for(int i =k+1;i<prefix.size();i++){
        res=max(res,prefix[i]-prefix[i-k-1]);
    }
    return res;
    }
};
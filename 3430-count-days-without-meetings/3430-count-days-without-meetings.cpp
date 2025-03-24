class Solution {
public:
    int countDays(int total, vector<vector<int>>& meetings) {
        int days=0;
        sort(meetings.begin(),meetings.end(),[](const vector<int>&a,const vector<int>&b){
            return a[0]<b[0];
        });
        int currDay=0;
        for(auto &it:meetings){
            int start=it[0];
            int end= it[1];
            if(start<=currDay){
                currDay=max(currDay,end);
            }else{
                days+=(start-currDay-1);
                currDay=max(currDay,end);
            }
        }
        //add reamaining days(days-last day of meetings array)
        // if(currDay<total)
        days+=(total-currDay);
        return days;
    }
};
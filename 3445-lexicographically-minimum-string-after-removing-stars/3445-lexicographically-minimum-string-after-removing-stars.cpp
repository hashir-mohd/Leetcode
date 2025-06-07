class Solution {

    struct Compare {
        bool operator()(const pair<char, int>& a, const pair<char, int>& b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        }
    };

public:
    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> pq;
        int n =s.size();
        vector<int> res(n,0);

        for(int i =0 ;i < n; i++){
            if(s[i]=='*'){
                res[i]=1;
                auto [ch,idx]=pq.top();
                pq.pop();
                res[idx]=1;
            }else{
                pq.push({s[i],i});
            }
        }

        string ans="";
        for(int i =0 ;i < n; i++){
            if(res[i]==0){
                ans+=s[i];
            }
            
        }
        return ans;
    }
};
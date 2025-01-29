using ppi = pair<char, int>;
class Solution {
public:
    struct comp {
        bool operator()(ppi& a, ppi& b) {
            return a.second < b.second; 
        }
    };

    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<ppi, vector<ppi>, comp> pq;
        queue<pair<ppi,int>> cooldown;
        unordered_map<char, int> mpp;
        int time = 0;

        // mapping the frequencies
        for (int i = 0; i < tasks.size(); i++) {
            mpp[tasks[i]]++;
        }
        for (auto it : mpp) {
            pq.push({it.first, it.second}); 
        }

        while(!pq.empty() || !cooldown.empty()){
            time++;
            if(!pq.empty()){
                auto [ task,freq]=pq.top();
                pq.pop();

                if(freq-1>0){
                    cooldown.push({{task,freq-1}, time+n});
                }
            }

            if(!cooldown.empty() && cooldown.front().second==time){
                pq.push({cooldown.front().first});
                cooldown.pop();
            }

        }
        return time;

    }
};
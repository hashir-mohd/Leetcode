class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);

        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int> dist(n+1,1e9);
        dist[0]=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[k]=0;
        pq.push({k,0});

        while(!pq.empty()){
            int node=pq.top().first;
            int dis=pq.top().second;
            pq.pop();

            for(auto &it:adj[node]){
                int adjNode=it.first;
                int edW=it.second;
                int newDis=dis+edW;
                if(newDis<dist[adjNode]){
                    dist[adjNode]=newDis;
                    pq.push({adjNode,newDis});
                }
            }
        }
        int res=INT_MIN;
        for(auto it:dist){
            if(it==1e9) return -1;
            res=max(res,it);
        }
        return res;

    }
};
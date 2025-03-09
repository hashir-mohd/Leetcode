class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int start=0;start<n;start++){
            if(color[start]==-1){
                color[start]=0;
                queue<int>q;
                q.push(start);

                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(auto &neighbour:graph[node]){
                        if(color[neighbour]==-1){
                            color[neighbour]=1-color[node];
                            q.push(neighbour);
                        }
                        else if(color[neighbour]==color[node]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;

    }
};
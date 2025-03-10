class Solution {

    bool dfs(vector<vector<int>>& adj,int node, vector<int>&visited,vector<int>&path,vector<int>&loopNodes){
        visited[node]=1;
        path[node]=1;
        int n = adj.size();
        for(auto &neighbour:adj[node]){
            if(!visited[neighbour]){
                if(dfs(adj,neighbour,visited,path,loopNodes)){
                    return true;
                }
            }
            else if(path[neighbour]){
                for(int i= 0;i<n;i++){
                    if(path[i]==1){
                        loopNodes[i]=1;
                    }
                }
                return true;
            }
        }
        
        path[node]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n= adj.size();
        vector<int> loopNodes(n,0);
        vector<int> path(n,0);
        vector<int> visited(n,0);
        vector<int> res;
        for(int i =0; i<n;i++){
            if(!visited[i]){
                dfs(adj,i,visited,path,loopNodes);
            }
        }
        
        
        for(int i=0;i<n;i++){
            if(loopNodes[i]==0){
                res.push_back(i);
            }
        }
        return res;

    }
};
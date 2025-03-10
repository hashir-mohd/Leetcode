class Solution {
    bool dfs(vector<vector<int>>& adj,int node, vector<int>&visited,vector<int>&path,stack<int>&s){
        visited[node]=1;
        path[node]=1;
        
        for(auto &neighbour:adj[node]){
            if(!visited[neighbour]){
                if(dfs(adj,neighbour,visited,path,s)){
                    return true;
                }
            }
            else if(path[neighbour]){
                return true;
            }
        }
        s.push(node);
        path[node]=0;
        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        int n= adj.size();
        vector<int> path(n,0);
        vector<int> visited(n,0);
        stack<int> s;
        vector<int> topo;
        for(int i =0; i<n;i++){
            if(!visited[i]){
                if(dfs(adj,i,visited,path,s)){
                    return topo; 
                }
            }
        }
        
        
        while(!s.empty()){
            topo.push_back(s.top());
            s.pop();
        }
        return topo;
    }
};
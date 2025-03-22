class Solution {
    void traverse(int node,vector<vector<int>>&adj,set<int>&nodes,vector<int>&visited){
        visited[node]=1;
        nodes.insert(node);
        for(auto &neighbour:adj[node]){
            if(!visited[neighbour]){
                traverse(neighbour,adj,nodes,visited);
            }
        }
    }

    bool check(set<int>&nodes,vector<vector<int>>&adj){
        int n= nodes.size();
        int edges= n-1;
        for(auto &it:nodes){
            if(adj[it].size()<edges)return false;
        }
        return true;
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        //making adjacency list
        vector<vector<int>> adj(n);
        for(auto &it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans=0;
        vector<int> visited(n,0); //0->not visited
        for(int i =0;i<n;i++){
            if(!visited[i]){
                set<int> nodes;
                traverse(i,adj,nodes,visited);
                //check for completeness
                if(check(nodes,adj)) ans++;
            }
        }
        return ans;

    }
};
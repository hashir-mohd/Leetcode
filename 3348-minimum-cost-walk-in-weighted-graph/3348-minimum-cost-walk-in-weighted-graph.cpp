class Solution {
public:
    int dfs(int node,vector<vector<pair<int,int>>> &adj,int root,vector<int>&visited,vector<int>&parent){
        visited[node]=1;
        parent[node]=root;
        int cost=INT_MAX;

        for(auto &[neighbour,weight]:adj[node]){
            cost&=weight;
            if(!visited[neighbour]){
                
                cost &=dfs(neighbour,adj,root,visited,parent);
            }
        }
        return cost;
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        //make adjacency list
        vector<vector<pair<int,int>>> adj(n);
        for(auto & it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        vector<int> parent(n);
        for(int i =0;i<n;i++){
            parent[i]=i;
        }
        vector<int> cost(n);
        vector<int> visited(n,0);
        //dfs
        for(int i =0;i<n;i++){
            if(!visited[i]){
                visited[i]=1;
                cost[i]=dfs(i,adj,i,visited,parent);
            }
        }

        //solving queries
        vector<int>ans;
        for(auto &query:queries){
            int start=query[0];
            int end=query[1];
            if(parent[start]!= parent[end]){
                ans.push_back(-1);
            }else{
                ans.push_back(cost[parent[start]]);
            }
        }
        return ans;

    }
};
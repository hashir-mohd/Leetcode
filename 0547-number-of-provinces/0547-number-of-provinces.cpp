class Solution {

    void traversal(vector<vector<int>> &adj,int node,vector<int>& visited){
        int n= adj.size();
        queue<int>q;
        q.push(node);
        visited[node]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int i =0 ;i < adj[node].size(); i++){
                int currNode=adj[node][i];
                if(visited[i]==0 && currNode==1){
                    visited[i]=1;
                    q.push(i);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n,0);
        // visited[0]=1;
        int provinces=0;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                provinces++;
                traversal(isConnected,i,visited);
            }
            
        }

        return provinces;
    }
};
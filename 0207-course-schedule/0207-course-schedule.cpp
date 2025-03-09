class Solution {

    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& path){
        
        visited[node]=1;
        path[node]=1;

        for(auto &neighbour:adj[node]){
            if(path[neighbour]==1 && visited[neighbour]==1){
                return true;
            }
            else if(!visited[neighbour]){
                visited[neighbour]=1;
                path[neighbour]=1;
                if(dfs(neighbour,adj,visited,path)){
                    return true;
                }
                path[neighbour]=0;
                
            }
        }
        
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //making adjacency list
        int n= prerequisites.size();
        vector<vector<int>> adj(numCourses);
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        vector<int> visited(numCourses,0);
        vector<int> path(numCourses,0);

        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                visited[i]=1;
                if(dfs(i,adj,visited,path)){
                    return false;
                }
                path[i]=0;
            }
        }
        return true;
    }
};
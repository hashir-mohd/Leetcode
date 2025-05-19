class Solution {

    bool hasCycleUtil(long long node, long long parent, vector<vector<long long>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for (long long neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (hasCycleUtil(neighbor, node, adj, visited))
                    return true;
            } else if (neighbor != parent) {
                return true; 
            }
        }
        return false;
    }
public:
    long long maxScore(int n, vector<vector<int>>& edges) {
        if(n==1)return 1;
        if(n==2)return 2;
        vector<vector<long long>> adj(n);
        for (const auto& edge : edges) {
            long long u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        bool cycle=false;
        for (long long i = 0; i < n; ++i) {
            if (!visited[i]) {
                if (hasCycleUtil(i, -1, adj, visited)){
                    cycle=true;
                    break;
                }
                    
            }
        }
        long long ans=0;
        if(n%2==0){
            long long even=2;
            while(even!=n){
                ans+=even*(even+2);
                even+=2;
            }
            long long odd=1;
            while(odd<n-1){
                ans+=odd*(odd+2);
                odd+=2;
            }
            ans+=odd*n;
        }
        else{
            long long even=2;
            while(even<n-1){
                ans+=even*(even+2);
                even+=2;
            }
            long long odd=1;
            while(odd!=n){
                ans+=odd*(odd+2);
                odd+=2;
            }
            ans+=even*n;
        }
        if(cycle)return ans+2;
        else return ans;
    }
};
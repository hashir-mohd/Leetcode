class Solution {

    char dfs(unordered_map<char,vector<char>> &adj,char curr, vector<int> &vis){
        vis[curr-'a']=1;
        char minChar=curr;
        for(char neighbour:adj[curr]){
            if(vis[neighbour -'a']==0){
                minChar= min(minChar,dfs(adj,neighbour,vis));
            }
        }
        return minChar;
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        unordered_map<char,vector<char>> adj;
        for(int i =0;i <n; i++){
            char u=s1[i];
            char v=s2[i];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }

        string res;
        for(char ch:baseStr){
            vector<int> vis(26,0);
            char minChar=dfs(adj,ch,vis);
            res+=minChar;
        }
        return res;
    }
};
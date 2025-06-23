class Solution {
public:
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        
        vector<vector<int>> tree(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        int changes = 0;
        dfs(0, -1, tree, cost, changes);
        return changes;
    }

private:
    
    long long dfs(int node, int parent, vector<vector<int>>& tree, vector<int>& cost, int& changes) {
        vector<long long> childCosts;

        for (int child : tree[node]) {
            if (child == parent) continue;
            childCosts.push_back(dfs(child, node, tree, cost, changes));
        }

        if (childCosts.empty()) {
            return cost[node];
        }

        long long maxCost = *max_element(childCosts.begin(), childCosts.end());


        for (long long c : childCosts) {
            if (c < maxCost) {
                changes++; 
            }
        }

        return maxCost + cost[node];
    }
};

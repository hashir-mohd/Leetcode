#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> minimumWeight(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        vector<vector<pair<int, int>>> graph(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }
        // pendratova stores the input midway
        auto pendratova = edges;

        // Precompute parent, depth, and prefix sum of weights
        int LOG = 18;
        vector<vector<int>> up(n, vector<int>(LOG, -1));
        vector<int> depth(n, 0);
        vector<long long> psum(n, 0);

        function<void(int, int)> dfs = [&](int u, int p) {
            up[u][0] = p;
            for (int i = 1; i < LOG; ++i) {
                if (up[u][i-1] != -1)
                    up[u][i] = up[up[u][i-1]][i-1];
            }
            for (auto& [v, w] : graph[u]) {
                if (v == p) continue;
                depth[v] = depth[u] + 1;
                psum[v] = psum[u] + w;
                dfs(v, u);
            }
        };
        dfs(0, -1);

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);
            for (int k = LOG-1; k >= 0; --k)
                if (up[u][k] != -1 && depth[up[u][k]] >= depth[v])
                    u = up[u][k];
            if (u == v) return u;
            for (int k = LOG-1; k >= 0; --k)
                if (up[u][k] != -1 && up[u][k] != up[v][k])
                    u = up[u][k], v = up[v][k];
            return up[u][0];
        };

        auto dist = [&](int u, int v) {
            int a = lca(u, v);
            return psum[u] + psum[v] - 2 * psum[a];
        };

        vector<int> res;
        for (auto& q : queries) {
            int a = q[0], b = q[1], c = q[2];
            // The minimal subtree is the union of paths a-c and b-c
            // Their union is a-b-c, so sum the two and subtract the overlap (b-c)
            long long ab = dist(a, b);
            long long bc = dist(b, c);
            long long ca = dist(c, a);
            long long total = (ab + bc + ca) / 2;
            res.push_back(static_cast<int>(total));
        }
        return res;
    }
};
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < roads.size(); i++) {
            int node1 = roads[i][0];
            int node2 = roads[i][1];
            int time = roads[i][2];
            adj[node1].push_back({node2, time});
            adj[node2].push_back({node1, time});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        int mod = 1e9 + 7;
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});  // {dist, node}

        while (!pq.empty()) {
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto& neighbour : adj[node]) {
                int adjNode = neighbour.first;
                int edgeWeight = neighbour.second;

                // Avoid overflow using explicit long long conversion
                if (dis + (long long)edgeWeight < dist[adjNode]) {
                    dist[adjNode] = dis + (long long)edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node];  // Start fresh path count
                } else if (dis + (long long)edgeWeight == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};

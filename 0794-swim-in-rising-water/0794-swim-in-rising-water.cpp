class Solution {
public:
    int swimInWater(vector<vector<int>>& heights) {
        
        int n = heights[0].size();
        
        
        vector<vector<int>> efforts(n, vector<int>(n, INT_MAX));
        efforts[0][0] = heights[0][0];
        
        
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.emplace(heights[0][0], 0, 0);
        
        
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while (!pq.empty()) {
            auto [effort, i, j] = pq.top();
            pq.pop();
            
            
            if (i == n - 1 && j == n - 1)
                return effort;
            
            // Explore all four directions.
            for (auto [di, dj] : directions) {
                int ni = i + di;
                int nj = j + dj;
                
                if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                    int currentEffort = max(effort, heights[ni][nj]);
                    if(currentEffort<efforts[ni][nj]){
                        efforts[ni][nj]=currentEffort;
                        pq.emplace(efforts[ni][nj],ni,nj);
                    }
                }
            }
        }
        return -1;
        
    }
};
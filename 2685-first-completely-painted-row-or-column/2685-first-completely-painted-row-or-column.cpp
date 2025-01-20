class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        if (m == 1 || n == 1)
            return 0;
        vector<pair<int, int>> v(m * n + 1);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                v[mat[i][j]] = {i, j};
            }
        }

        vector<int> rows(m + 1, 0);
        vector<int> col(n + 1, 0);
        int res = INT_MAX;
        for (int i = 0; i < arr.size(); i++) {
            auto it = v[arr[i]];
            int j = it.first;
            int k = it.second;
            rows[j] = rows[j] + 1;
            col[k] = col[k] + 1;
            if (rows[j] == n) {
                res = i;
                return res;
            }
            if (col[k] == m) {
                res = i;
                return res;
            }
        }
        return res;
    }
};
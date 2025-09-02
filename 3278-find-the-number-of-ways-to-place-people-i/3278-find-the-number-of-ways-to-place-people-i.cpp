class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        

        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[1] == b[1])
                     return a[0] < b[0];
                 return a[1] > b[1];    
             });

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                if (x2 >= x1 && y2 <= y1) {
                    if(n==2) return 1;
                    int flag=true;
                    for (int k = 0; k < n; k++) {
                        if (k != i && k != j) {
                            int x = points[k][0], y = points[k][1];
                            if ((x >= x1 && x <= x2) && (y >= y2 && y <= y1)) {
                                flag=false;
                            }
                        }
                    }
                    if(flag) res++;
                }
            }
        }
        return res;
    }
};
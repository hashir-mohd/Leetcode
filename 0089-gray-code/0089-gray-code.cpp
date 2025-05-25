class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int>res;
        for (int i = 0; i < (1 << n); ++i) {
            int gray = i ^ (i >> 1);
            res.push_back(gray);
        }
        return res;
    }
};
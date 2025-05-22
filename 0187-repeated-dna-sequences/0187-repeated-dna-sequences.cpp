class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        set<string> seen, repeated;
        for (int i = 0; i + 9 < n; ++i) {
            string sub = s.substr(i, 10);
            if (seen.count(sub)) {
                repeated.insert(sub);
            } else {
                seen.insert(sub);
            }
        }
        return vector<string>(repeated.begin(), repeated.end());
    }
};
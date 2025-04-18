class Solution {
    void func(string &modified, string curr) {
        int len = curr.size();
        char ch = curr[0];
        string length = to_string(len);
        modified += length;
        modified += ch;
    }

    string rec(int n) {
        if (n == 1) return "1";

        string curr = rec(n - 1);
        string modified = "";

        int i = 0;
        while (i < curr.size()) {
            char ch = curr[i];
            int count = 0;

            // Count how many times ch repeats consecutively
            while (i < curr.size() && curr[i] == ch) {
                count++;
                i++;
            }

            // Append count and character to result
            modified += to_string(count);
            modified += ch;
        }

        return modified;
    }

public:
    string countAndSay(int n) {
        return rec(n);
    }
};

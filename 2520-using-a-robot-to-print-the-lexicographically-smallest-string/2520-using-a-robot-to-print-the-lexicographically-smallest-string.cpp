class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();
        vector<char> min_suffix(n);
        min_suffix[n - 1] = s[n - 1];

        for (int i = n - 2; i >= 0; --i) {
            min_suffix[i] = min(s[i], min_suffix[i + 1]);
        }

        stack<char> st;
        string result;
        int i = 0;

        while (i < n) {
            st.push(s[i]); 
            i++;

            while (!st.empty() && (i == n || st.top() <= min_suffix[i])) {
                result += st.top();
                st.pop();
            }
        }

        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};
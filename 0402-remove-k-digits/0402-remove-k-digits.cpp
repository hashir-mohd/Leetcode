class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        if (k == num.size())
            return "0";
        for (char c : num) {

            while (!st.empty() && st.top() > c && k > 0) {
                st.pop();
                k--;
            }
            if (st.empty() && c == '0')
                continue;
            st.push(c);
        }
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        string ans;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans.empty() ? "0" : ans;
    }
};
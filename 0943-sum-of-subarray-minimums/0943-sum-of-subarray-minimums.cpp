class Solution {
public:
    vector<int> nextSmaller(vector<int> arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> next(n, n);
        // st.push(n - 1);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                next[i] = st.top();
            }
            st.push(i);
        }
        return next;
    }

    vector<int> prevSmaller(vector<int> arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> prev(n, -1);
        // st.push(0);
        for (int i = 0; i <n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                prev[i] = st.top();
            }
            st.push(i);
        }
        return prev;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> next = nextSmaller(arr);
        vector<int> prev = prevSmaller(arr);

        long long sum = 0;
        int mod = 1000000007;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            // Calculate the contribution of arr[i]
            long long prevCount = i - prev[i];
            long long nextCount = next[i] - i;
            long long contribution = (arr[i] * prevCount % mod * nextCount % mod) % mod;

            // Add to the total sum
            sum = (sum + contribution) % mod;
        }

        return (int)sum;
    }
};
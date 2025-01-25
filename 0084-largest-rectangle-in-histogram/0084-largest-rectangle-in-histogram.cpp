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
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        vector<int> next = nextSmaller(arr);
        vector<int> prev = prevSmaller(arr);

        int res=0;
        for(int i =0 ;i <n ;i++){
            int width= next[i]-prev[i]-1;
            int area= width*arr[i];
            res=max(res,area);
        }
        return res;
        
    }
};
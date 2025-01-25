class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long answer= 0;
        stack <int> st;
        for(int right= 0; right<=n; right++){
            while(!st.empty() && (right==n || nums[st.top()]>=nums[right])){
                int mid= st.top();
                st.pop();
                int left = st.empty()?-1:st.top();
                answer-=(long long)nums[mid]*(right-mid)*(mid-left);
            }
            st.push(right);
        }
        st.pop();
        for (int right = 0; right <= n; ++right) {
            while (!st.empty() &&
                   (right == n || nums[st.top()] <= nums[right])) {
                int mid = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                answer += (long long)nums[mid] * (right - mid) * (mid - left);
            }
            st.push(right);
        }
        return answer;
    }
};
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int> st;
        st.push(arr[0]);
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            int current= arr[i];
            bool collided= false;
            if (arr[i] > 0)
                st.push(arr[i]);
            else { // arr[i] is negative
                while (!st.empty() && st.top() > 0) {
                    if (st.top() < abs(current)) {
                        st.pop();
                    } else if (st.top() == abs(current)) {
                        st.pop();
                        collided=true;
                        break;
                    } else {
                        break;
                    }
                }
                
                // If stack is empty or top of stack is negative, push current asteroid
                if (st.empty() || st.top() < 0 ) {
                    if(collided==false)
                    st.push(current);
                }
            }
        }
        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};
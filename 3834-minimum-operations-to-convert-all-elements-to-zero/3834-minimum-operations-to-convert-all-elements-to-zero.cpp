class Solution {
private:
vector<int> nextSmaller(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, n); 
    stack<int> st;          

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            res[i] = st.top();
        }

       
        if (arr[i] == 0) res[i] = INT_MAX;

        st.push(i);
    }
    return res;
}

vector<int> prevSmaller(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            res[i] = st.top();
        }

        
        if (arr[i] == 0) res[i] = INT_MAX;

        st.push(i);
    }
    return res;
}

public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        set<pair<int,int>> st;
        vector<int> ns= nextSmaller(nums);
        vector<int> ps= prevSmaller(nums);

        // for(int i =0;i<n;i++){
        //     cout<< ps[i] <<" ";
        // }
        // cout << endl;
        // for(int i =0;i<n;i++){
        //     cout<< ns[i] <<" ";
        // }

        for(int i =0;i<n;i++){
            st.insert({ps[i],ns[i]});
        }
        if(st.find({INT_MAX,INT_MAX})!= st.end()){
            st.erase({INT_MAX,INT_MAX});
        }
        return st.size();
        
        
    }
};
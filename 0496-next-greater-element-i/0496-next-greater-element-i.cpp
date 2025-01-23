class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> ans(n,-1);
        stack <int> s;
        for(int i = n-1;i >=0;i--){
            while(!s.empty() && s.top()<=nums2[i]){
                s.pop();
            }
            if(!s.empty()){
                ans[i]=s.top();
            }
            s.push(nums2[i]);
        }

        unordered_map<int,int> mpp;
        for(int i =0 ;i < n; i++){
            mpp[nums2[i]]=ans[i];
        }
        vector<int> res;
        for(int i =0 ;i < nums1.size();i++){
            if(mpp.find(nums1[i]) != mpp.end()){
                res.push_back(mpp[nums1[i]]);
            }
        }
        return res;

    }
};
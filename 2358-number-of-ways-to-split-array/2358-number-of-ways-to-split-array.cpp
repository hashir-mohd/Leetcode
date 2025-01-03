class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long> preSum;
        long long sum=0;
        for(auto &it:nums){
            sum+=it;
            preSum.push_back(sum);
        }
        int res=0;
        int n = nums.size();
        for(int i =0 ;i < nums.size()-1;i++){
            if(preSum[i]>=(preSum[n-1]-preSum[i]))res++;
            cout<<preSum[i] << "  " <<preSum[n-1]-preSum[i]<<endl;
        }
        return res;

    }
};
class Solution {
    bool solve(int k, vector<int> &nums,int i,int cap){
        int n = nums.size();
        int flag=true;
        for(int i =0 ;i < n;i++){
            if(nums[i]<=cap){
                i++;
                k--;
            }
        }
        return k<=0;
    }

public:
    int minCapability(vector<int>& nums, int k) {
        int low=INT_MAX;
        int high=INT_MIN;
        for(auto &it:nums){
            low=min(low,it);
            high=max(high,it);
        }
        int n = nums.size();
        
        int capability=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(solve(k,nums,0,mid)){
                capability=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return capability;
    }
};
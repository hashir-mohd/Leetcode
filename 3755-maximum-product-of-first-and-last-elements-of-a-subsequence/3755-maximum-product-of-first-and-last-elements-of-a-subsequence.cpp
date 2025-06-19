class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        vector<int> suffMin(n),suffMax(n);
        long long res= LLONG_MIN;
        suffMin[n-1]=nums[n-1];
        suffMax[n-1]=nums[n-1];
        for(int i =n-2;i >=0 ;i --){
            suffMin[i]=min(suffMin[i+1],nums[i]);
            suffMax[i]=max(suffMax[i+1],nums[i]);
        }

        for(int i =0 ;i <= n-m; i++){
            if(nums[i]<0){
                res=max(res,nums[i]*1LL *suffMin[i+m-1]);
            }else{
                res=max(res,nums[i]*1LL *suffMax[i+m-1]);
            }
        }
        return res;
    }
};
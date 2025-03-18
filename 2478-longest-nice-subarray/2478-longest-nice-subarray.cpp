class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int res=1;
        int right=1;
        int left=0;
        int n = nums.size();
        while(right<n){
            bool flag=true;
            for(int i = left;i<right;i++){
                if((nums[i] & nums[right])!=0){
                    flag=false;
                    break;
                }
            }
            if(flag){
                res=max(res,right-left+1);
                right++;
            }else{
                left++;
            }
        }
        return res;
    }
};
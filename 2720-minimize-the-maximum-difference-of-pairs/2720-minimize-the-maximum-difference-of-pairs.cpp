class Solution {

    int func(vector<int>&nums,int x){
        int idx=0,count=0;
        while(idx<nums.size()-1){
            if(nums[idx+1]-nums[idx]<=x){
                count++;
                idx++;
            }
            idx++;
        }
        return count;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int left=0;
        int right= nums[n-1]-nums[0];
        while(left<right){
            int mid= left+(right-left)/2;
            if(func(nums,mid)>=p){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left;
    }
};
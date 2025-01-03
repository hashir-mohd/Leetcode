class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res=0;
        int count=0;
        for(int i =0;i<nums.size();i++){
            if(nums[i]!=1)count=0;
            else{count++;}
            cout<< count<< endl;
            res=max(res,count);
        }
        return res;
    }
};
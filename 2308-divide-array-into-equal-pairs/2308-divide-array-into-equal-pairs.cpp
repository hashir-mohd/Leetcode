class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<n){
            
            int count=1;
            while(i+1<n && nums[i]==nums[i+1]){
                count++;
                i++;
            }
            if(count%2!=0)return false;
            i++;
        }
        return true;
    }
};
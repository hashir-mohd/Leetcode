class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el=nums[0];
        int count =1;
        for(int i =1 ; i<nums.size(); i++){
            
            if(nums[i]==el){
                count++;
            }
            else{
                count--;
            }
            if(count == 0){
                el=nums[i];
                count++;
            }
        }
        return el;
    }
};
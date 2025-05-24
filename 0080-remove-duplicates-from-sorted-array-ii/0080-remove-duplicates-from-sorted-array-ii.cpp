class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2)
            return n;

        int left = 0;
        int right = 1;
        int count = 1;
        int k = 0;
        for (right; right < n; right++) {
            
            if (nums[right] != nums[right - 1]) {
                count = min(count, 2);
                for (int i = 0; i < count; i++) {
                    nums[left] =nums[right - 1];
                    k++;
                    left++;
                }
                count=1;
            }else{
                count++;
            }
            
        }
        count = min(count, 2);
        for (int i = 0; i < count; i++) {
            nums[left] =nums[right - 1];
            k++;
            left++;
        }
        return left;
    }
};
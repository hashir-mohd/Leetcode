class Solution {
public:
    bool canMakeEqual(vector<int>& a, int k) {
            // making all equal to 1
            int rem=k;
            int n= a.size();
            bool possible=true;
            vector<int> nums= a;
            for(int i =0; i< n-1 ; i++){
                if(nums[i]==-1 ){
                    if(rem>0){
                        rem--;
                        nums[i]=1;
                        nums[i+1]*=-1;
                    }
                    else{
                        possible=false;
                        break;
                    }
                }
            }
            if(nums[n-1]==-1){
                possible=false;
            }
            if (possible && nums[n - 1] == 1) return true;
            possible=true;
            rem=k;
            nums=a;
            for(int i =0; i< n-1 ; i++){
                if(nums[i]==1 ){
                    if(rem>0){
                        rem--;
                        nums[i]=-1;
                        nums[i+1]*=-1;
                    }
                    else{
                        possible=false;
                        break;
                    }
                }
            }
            if (possible && nums[n - 1] == -1) return true;
            return false;

    }
};
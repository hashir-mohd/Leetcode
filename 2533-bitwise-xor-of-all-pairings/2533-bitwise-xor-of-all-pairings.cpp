class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int c1=nums1.size();
        int c2=nums2.size();
        if(c1%2==0 && c2%2==0){
            return 0;
        } else if(c1%2==1 && c2%2==0){
            int res=0;
            for(int i =0;i<c2;i++){
                res=res^nums2[i];
            }
            return res;
        }else if(c1%2==0 && c2%2==1){
            int res=0;
            for(int i =0;i<c1;i++){
                res^=nums1[i];
            }
            return res;
        }else{
            int res=0;
            for(int i =0;i<c1;i++){
                res^=nums1[i];
            }
            for(int i =0;i<c2;i++){
                res^=nums2[i];
            }
            return res;
        }
        
        
    }
};
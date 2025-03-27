class Solution {
public:
    int minimumIndex(vector<int>& a) {
        int maj=a[0];
        int count=1;
        int n=  a.size();
        for(int i =1;i<n;i++){
            if(a[i]==maj){
                count++;
            }else{
                count--;
                if(count==0){
                    maj=a[i];
                    count=1;
                }
            }
        }

        int freq=0;
        vector<int> prefix(n);
        for(int i =0;i<n;i++){
            if(a[i]==maj){
                freq++;
            }
            prefix[i]=freq;
        }
        

        for(int i =0;i<n-1;i++){
            if((prefix[i]*2>i+1) && (prefix[n-1]-prefix[i])*2>n-i-1)return i;
        }
        return -1;

    }
};
class Solution {
public:
    int candy(vector<int>& arr) {
        int n = arr.size();
        int candies=n;
        int i =1;
        
        while(i<n){
            if(arr[i]==arr[i-1]){
                i++;
                continue;
            }
            int peak =0;
            while(arr[i]>arr[i-1]){
                peak++;
                candies+=peak;
                i++;
                if(i==n) return candies;
            }
            int valley=0;
            while(i<n && arr[i]<arr[i-1]){
                valley++;
                candies+=valley;
                i++;
            }
            candies-= min(peak,valley);
        }
        return candies;
        
        
    }
};
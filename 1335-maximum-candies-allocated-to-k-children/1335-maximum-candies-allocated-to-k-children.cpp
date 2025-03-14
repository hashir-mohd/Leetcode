class Solution {

    bool solve(long long mid, vector<int>&v,long long k){
        for(int i =0 ;i < v.size();i++){
            k-=(v[i]/mid);
        }
        return k<=0;
    }
public:
    int maximumCandies(vector<int>& v, long long k) {
        long long left=1;
        long long sum = accumulate(v.begin(), v.end(), 0LL);
        long long right= sum/k;
        long long ans=0;
        if(sum<k)return 0;

        while(left<=right){
            long long mid= left + (right-left)/2;
            if(solve(mid,v,k)){
                left=mid+1;
                ans=mid;
            }
            else{
                right=mid-1;
            }
        }
        return ans;

    }
};
#define ll long long
class Solution {
public:
    long long maximumTripletValue(vector<int>& a) {
        
        
        int n = a.size();
        vector<ll>nums(n);
        for(int i=0;i<n;i++){
            nums[i]=(ll)a[i];
        }
        vector<ll> pre_max(n,0);
        vector<ll> suff_max(n,0);
        ll maxi=INT_MIN;
        for(int i =1;i<n-1;i++){
            maxi=max(maxi,nums[i-1]);
            pre_max[i]=maxi;
        }
        maxi=INT_MIN;
        for(int i =n-2;i>=0;i--){
            maxi=max(maxi,nums[i+1]);
            suff_max[i]=maxi;
        }
        ll ans=0;
        for(int i=1;i<n-1;i++){
            ll val=(pre_max[i]-nums[i])*suff_max[i];
            ans=max(ans,val);
        }
        return ans;
    }
};
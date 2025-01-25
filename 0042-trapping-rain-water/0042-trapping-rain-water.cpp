class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        vector<int> preMax(n);
        int maxx= height[0];
        for(int i = 0; i <n ;i++){
            maxx= max(maxx,height[i]);
            preMax[i]=maxx;
        }
        int minn= height[n-1];
        vector<int> suffMax(n);
        for(int i =n-1; i>=0;i--){
            minn= max(minn,height[i]);
            suffMax[i]=minn;
        }
        for(auto it:suffMax){
            cout<< it;
        }
        int water=0;
        for(int i =0 ;i <n;i++){
            int leftMax=preMax[i];
            int rightMax= suffMax[i];
            if(height[i]<leftMax && height[i]<rightMax){
                water+= (min(leftMax,rightMax)-height[i]);
            }
        }
        return water;
    }
};
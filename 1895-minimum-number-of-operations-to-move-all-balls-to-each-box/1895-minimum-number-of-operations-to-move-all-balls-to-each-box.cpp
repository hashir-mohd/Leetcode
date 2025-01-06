class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        int j =0;
        vector<int> res;
        for(int i =0 ;i<n;i++){
            int operations=0;
            for(int left=0;left<j;left++){
               if(boxes[left]=='1'){
                operations+=(j-left);
               } 
            }
            for(int right=j+1;right<n;right++){
                if(boxes[right]=='1'){
                    operations+=(right-j);
                }
            }
            j++;
            res.push_back(operations);
        }
        return res;
    }
    
};
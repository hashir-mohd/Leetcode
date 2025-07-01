class Solution {
public:
    int possibleStringCount(string word) {
        int count=1;
        int res=1;
        int n = word.size();
        for(int i =1;i <n ;i++){
            if(word[i]!=word[i-1]){
                res+=(count-1);
                count=0;
            }
            count++;
        }
        res+=(count-1);
        return res;
        
        
    }
};
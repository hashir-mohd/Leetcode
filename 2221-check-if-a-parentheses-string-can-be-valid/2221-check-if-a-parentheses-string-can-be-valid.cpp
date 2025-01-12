class Solution {
public:
    bool canBeValid(string s, string locked) {
        int min =0, max =0;
        if(s.size()%2 ==1) return false;
        for(int i =0 ; i < s.size(); i++){
            if(s[i]=='(' && locked[i]=='1'){
                min++;
                max++;
            }
            else if(s[i]==')' && locked[i]=='1'){
                min--;
                max--;
            }
            else{
                min--;
                max++;
            }
            if(min<0) min=0;
            if(max<0) return false;
        }
        return (min==0);
    }
};
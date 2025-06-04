class Solution {
    string func(string &s1, string &s2){
        return (s1 > s2) ? s1 : s2;
    }

public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        string res="a";
        if(numFriends==1){
            return word;
        }

        for(int i =0;i < n ; i ++){
            if((n-numFriends+1+i)>n){
                string temp=word.substr(i);
                res=func(res,temp);
            }else{
                string temp=word.substr(i,n-numFriends+1);
                res=func(res,temp);
            }
        }
        return res;
    }
};
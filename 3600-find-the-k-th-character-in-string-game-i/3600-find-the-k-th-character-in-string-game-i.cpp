class Solution {
public:
    char kthCharacter(int k) {
        if(k==1){
            return 'a';
        }
        //generate string
        string curr= "a";
        while(curr.size()<=k){
            string temp=curr;
            for(int i =0 ;i < temp.size();i++){
                if(temp[i]=='z'){
                    temp[i]='a';
                    continue;
                }
                temp[i]=temp[i]+1;
            }
            curr+=temp;
        }
        cout<<curr<<endl;
        return curr[k-1];
        

    }
};
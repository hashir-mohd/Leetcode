class Solution {
public:
    int minMaxDifference(int num) {
        string s=to_string(num);

        //making largest number
        char temp;
        for( char ch:s){
            if(ch!='9'){
                temp=ch;
                break;
            }
        }
        string largest;
        for(int i=0;i<s.size();i++){
            if(s[i]==temp){
                largest+='9';
            }else{
                largest+=s[i];
            }
        }
        cout<<largest<<endl;

        //making smallest 
        for( char ch:s){
            if(ch!='0'){
                temp=ch;
                break;
            }
        }
        string smallest;
        for(int i=0;i<s.size();i++){
            if(s[i]==temp){
                smallest+='0';
            }else{
                smallest+=s[i];
            }
        }

        return stoi(largest)-stoi(smallest);
    }
};
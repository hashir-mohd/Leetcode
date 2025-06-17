class Solution {
public:
    string generateTag(string caption) {
        string res="#";
        bool capital=false;
        int n = caption.size();
        for(int i =0 ;i < n ; i++){
            if(caption[i]==' '){
                capital = true;
            }else{
                if(capital){
                    res+=toupper(caption[i]);
                }else{
                    res+=tolower(caption[i]);
                }
                capital=false;
            }
        }
        string temp=res.substr(0,100);
        temp[1]=tolower(temp[1]);
        return temp;
    }
};
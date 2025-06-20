class Solution {
public:
    int maxDistance(string str, int k) {
        //NE direction
        int rem=k;
        int res=0;
        int curr=0;
        for(auto& ch:str){
            
            if(ch=='N' || ch=='E'){
                curr++;
            }else{
                if(rem>0){
                    rem--;
                    curr++;
                }else{
                    curr--;
                }
            }
            res=max(curr,res);
        }

        //NW
        rem=k;
        curr=0;
        for(auto& ch:str){
            
            if(ch=='N' || ch=='W'){
                curr++;
            }else{
                if(rem>0){
                    rem--;
                curr++;
                }else{
                    curr--;
                }
            }
            res=max(curr,res);
        }
        

        //SE
        rem=k;
        curr=0;
        for(auto& ch:str){
            
            if(ch=='S' || ch=='E'){
                curr++;
            }else{
                if(rem>0){
                    rem--;
                curr++;
                }else{
                    curr--;
                }
            }
            res=max(curr,res);
        }
        
        //SW
        rem=k;
        curr=0;
        for(auto& ch:str){
            
            if(ch=='S' || ch=='W'){
                curr++;
            }else{
                if(rem>0){
                    rem--;
                curr++;
                }else{
                    curr--;
                }
            }
            res=max(curr,res);
        }
        
        return res;
    }
    };
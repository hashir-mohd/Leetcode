class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        set<string> ans;
        set<string> st;
        for(int i = 0; i <= n - 10; i++){
            string t = "";
            for(int j = 0; j < 10; j++){
                t += s[i + j];
            }
            if(st.find(t) != st.end()){
                ans.insert(t);
            }
            st.insert(t);
        }
        vector<string> answer;
        for(auto it : ans){
            answer.push_back(it);
        }
        return answer;
    }
};
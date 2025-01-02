class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        vector<int> arr;
        
        int count = 0;
        for (auto str : words) {
            char firstChar = str.front();
            char lastChar = str.back();
            if (isVowel(firstChar) && isVowel(lastChar)) {
                count++;
            }
            arr.push_back(count);
        }
        
        for(int i = 0; i< arr.size(); i++){
            cout << arr[i] <<" ";
        }
        vector<int> res;
        for(auto &query : queries){
            int startIndex= query[0];
            int endIndex = query[1];
            int a=0;
            if(startIndex==0){
                a=arr[startIndex];
            }
            else{
                a=arr[startIndex]-arr[startIndex-1];
            }
            res.push_back(arr[endIndex]-arr[startIndex]+a);
            

        }
        return res;
    }
};
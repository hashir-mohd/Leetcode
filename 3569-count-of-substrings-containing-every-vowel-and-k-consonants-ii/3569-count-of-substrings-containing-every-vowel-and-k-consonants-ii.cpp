class Solution {
    long atleastK(string word,int K){
        long res=0;
        int start=0;
        int end=0;
        unordered_map<char,int> vowels;
        int consonantCount=0;
        int n= word.length();
        while(end<n){
            char newLetter=word[end];
            if(isVowel(newLetter)){
                vowels[newLetter]++;
            }
            else{
                consonantCount++;
            }

            while(vowels.size()==5 and consonantCount>=K){
                res+=n-end;
                char startLetter=word[start];
                if(isVowel(startLetter)){
                    if(--vowels[startLetter]==0){
                        vowels.erase(startLetter);
                    }
                }else{
                    consonantCount--;
                }
                start++;
            }
            end++;
        }
        return res;
    }

    bool isVowel(char c){
        return c=='a' || c=='e' ||c=='i' ||c=='o' ||c=='u';
    }
public:
    long long countOfSubstrings(string word, int k) {
        return atleastK(word,k)-atleastK(word,k+1);
    }

};
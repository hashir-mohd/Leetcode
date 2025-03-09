class Solution {

    int check(string s1,string s2){
        int flag=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i])flag++;
        }
        return flag;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return 0;
        if (wordSet.find(beginWord) == wordSet.end()) {
            wordList.push_back(beginWord);
        }

        //creating adjacency list
        unordered_map<string,vector<string>>mpp;
        for(auto &curr:wordList){
            for(auto &adj:wordList){
                if(check(curr,adj)==1){
                    mpp[curr].push_back(adj);
                }
            }
        }
        
        queue<pair<string,int>>q;
        unordered_set<string> visited;
        q.push({beginWord,1});
        visited.insert(beginWord);
        while(!q.empty()){
            auto[word,level]=q.front();
            q.pop();
            if (word == endWord) return level;

            for(auto &neighbour:mpp[word]){
                if(visited.find(neighbour)==visited.end()){
                    visited.insert(neighbour);
                    q.push({neighbour,level+1});
                }
            }
        }
        return 0;



    }
};
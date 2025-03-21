#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, vector<string>> graph;
    unordered_map<string, int> state;
    unordered_set<string> suppliesSet;
    unordered_set<string> recipeSet;
    
    bool dfs(const string &node, vector<string>& result) {
        if (suppliesSet.count(node)) return true;
        if (!recipeSet.count(node)) return false;
        if (state[node] == 1) return false;
        if (state[node] == 2) return true;
        
        state[node] = 1;
        for (string &ing : graph[node]) {
            if (!dfs(ing, result))
                return false;
        }
        
        state[node] = 2;
        result.push_back(node);
        suppliesSet.insert(node);
        return true;
    }
    
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        suppliesSet = unordered_set<string>(supplies.begin(), supplies.end());
        for (auto &recipe : recipes) {
            recipeSet.insert(recipe);
        }
        
        for (int i = 0; i < recipes.size(); i++) {
            for (string &ing : ingredients[i]) {
                graph[recipes[i]].push_back(ing);
            }
        }
        
        vector<string> result;
        for (auto &recipe : recipes) {
            dfs(recipe, result);
        }
        
        return result;
    }
};

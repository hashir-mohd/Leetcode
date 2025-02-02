#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(unordered_map<char, int>& map2, unordered_map<char, int>& map1) {
        for (auto [ch, freq] : map2) {
            if (map1[ch] < freq) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        int left = 0, right = 0;
        unordered_map<char, int> map1, map2;
        pair<int, int> res = {0, INT_MAX-1};
        int n = s.size();

        for (char ch : t) {
            map2[ch]++;
        }

        while (right < n) {
            map1[s[right]]++;

            while (check(map2, map1)) { // Shrink window
                if (right - left + 1 < res.second - res.first+1) {
                    res = {left, right};
                }
                map1[s[left]]--;
                if (map1[s[left]] == 0) {
                    map1.erase(s[left]);
                }
                left++;  // Move left to reduce window size
            }
            right++;
        }

        if (res.second == INT_MAX-1) return ""; // No valid window found
        return s.substr(res.first, res.second - res.first + 1);
    }
};

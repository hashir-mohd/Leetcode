class Solution {
public:
    int atMostKDistinct(string& s, int k) {
        int n = s.size();
        int left = 0, res = 0;
        unordered_map<char, int> freq;

        for (int right = 0; right < n; ++right) {
            freq[s[right]]++;

            while (freq.size() > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) freq.erase(s[left]);
                left++;
            }

            res += (right - left + 1);
        }

        return res;
    }

    int numberOfSubstrings(string s) {
        int n = s.size();
        long long total = 1LL *n * (n + 1) / 2;
        long long withoutAllThree = atMostKDistinct(s, 2);
        return (int)(total - withoutAllThree);
    }
};

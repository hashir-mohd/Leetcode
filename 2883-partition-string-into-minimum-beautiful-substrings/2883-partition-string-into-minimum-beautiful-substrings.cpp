class Solution {
public:
    long long decimal(const string &s) {
        long long num = 0;
        for(char c : s) num = num*2 + (c-'0');
        return num;
    }
    
    bool beautiful(const string &s, int start, int end) {
        if(s[start] == '0') return false;
        long long num = 0;
        for(int i = start; i <= end; i++) num = num*2 + (s[i]-'0');
        while(num > 1) {
            if(num % 5 != 0) return false;
            num /= 5;
        }
        return num == 1;
    }
    
    int func(const string &s, int start) {
        int n = s.size();
        if(start >= n) return 0;
        
        int ans = INT_MAX;
        for(int i = start; i < n; i++) {
            if(beautiful(s, start, i)) {
                int res = func(s, i+1);
                if(res != INT_MAX) ans = min(ans, 1 + res);
            }
        }
        return ans;
    }
    
    int minimumBeautifulSubstrings(string s) {
        int res = func(s, 0);
        return res == INT_MAX ? -1 : res;
    }
};

class Solution {
    vector<int> parent;

    
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    
    void unionSet(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;
        if (px < py) parent[py] = px;
        else parent[px] = py;
    }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26);
        for (int i = 0; i < 26; ++i)
            parent[i] = i;

        for (int i = 0; i < s1.size(); ++i) {
            unionSet(s1[i] - 'a', s2[i] - 'a');
        }

        string result = "";
        for (char c : baseStr) {
            result += (char)(find(c - 'a') + 'a');
        }

        return result;
    }
};

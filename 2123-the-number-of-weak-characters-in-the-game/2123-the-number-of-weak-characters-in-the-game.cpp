class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] != b[0]) {

                     return a[0] > b[0];
                 }
                 return a[1] < b[1];
             });

        int weakCount = 0;
        int maxDefenseSeen = 0;

        for (const auto& property : properties) {
            int defense = property[1];

            if (defense < maxDefenseSeen) {
                weakCount++;
            }
            maxDefenseSeen = max(maxDefenseSeen, defense);
        }

        return weakCount;
    }
};
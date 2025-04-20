class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> freq;
        int total = 0;

        for (int num : answers) {
            freq[num]++;
        }

        for (auto& [x, count] : freq) {
            int groupSize = x + 1;
            int groups = (count + groupSize - 1) / groupSize;
            total += groups * groupSize;
        }

        return total;
    }
};

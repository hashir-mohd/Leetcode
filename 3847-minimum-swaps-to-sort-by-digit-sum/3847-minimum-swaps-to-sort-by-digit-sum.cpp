class Solution {
public:
    int getSum(int num) {
        int s = 0;
        while (num > 0) {
            s += num % 10;
            num /= 10;
        }
        return s;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; ++i) {
            arr.push_back({getSum(nums[i]), nums[i]});
        }
        sort(arr.begin(), arr.end());

        
        unordered_map<int, int> pos;
        for (int i = 0; i < n; ++i) {
            pos[arr[i].second] = i;
        }

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i] || pos[nums[i]] == i)
                continue;
            int cycle = 0, j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = pos[nums[j]];
                ++cycle;
            }
            if (cycle > 0)
                swaps += (cycle - 1);
        }
        return swaps;
    }
};
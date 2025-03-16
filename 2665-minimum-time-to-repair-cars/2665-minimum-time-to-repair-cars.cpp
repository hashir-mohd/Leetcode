using ll = long long;
class Solution {

    bool solve(ll time, int cars, vector<int>& ranks) {
        ll repairedCars = 0; 

        for (int i = 0; i < ranks.size(); i++) {
            repairedCars +=sqrt(
                1.0*time / ranks[i]); 
            if (repairedCars >= cars)
                return true;
        }

        return repairedCars >= cars;
    }

public:
    long long repairCars(vector<int>& ranks, int cars) {
        
         long long low = 1, high = 1LL * cars * cars * ranks[0];
        ll ans = high;
        while (low <= high) {
            ll mid = low + (high - low) / 2;

            if (solve(mid, cars, ranks)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
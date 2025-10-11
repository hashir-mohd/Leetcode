class Solution {
    int maxPoints = 0;
    vector<int> bestConfig;
    vector<vector<int>> memo;

    int helper(int idx, int arrows, vector<int> &bobArrows, 
                vector<int> &aliceArrows, int points) {
        int n = aliceArrows.size();
        if (idx == n - 1) {
            bobArrows[idx] = arrows;
            if (arrows > aliceArrows[idx]) points += idx;
            if (points > maxPoints) {
                maxPoints = points;
                bestConfig = bobArrows;
            }
            return points;
        }

        // prune if this state cannot do better
        // if (memo[idx][arrows] >= points) return;

        // win
        int take=0;
        if (arrows > aliceArrows[idx]) {
            auto temp = bobArrows;
            temp[idx] = aliceArrows[idx] + 1;
            take= helper(idx + 1, arrows - aliceArrows[idx] - 1, temp, aliceArrows, points + idx);
        }

        // not win
        int notTake;
        auto temp = bobArrows;
        temp[idx] = 0;
        notTake= helper(idx + 1, arrows, temp, aliceArrows, points);
        return    memo[idx][arrows] = max(take, notTake);

    }

public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int n = aliceArrows.size();
        vector<int> bobArrows(n, 0);
        memo.assign(n, vector<int>(numArrows + 1, -1));
        helper(0, numArrows, bobArrows, aliceArrows, 0);
        return bestConfig;
    }
};

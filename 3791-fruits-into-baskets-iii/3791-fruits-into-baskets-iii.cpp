#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        // Segment tree: each node stores the maximum capacity in its range.
        vector<int> seg(4 * n, 0);

        // Build the segment tree based on the baskets array.
        function<void(int, int, int)> build = [&](int pos, int l, int r) {
            if(l == r) {
                seg[pos] = baskets[l];
                return;
            }
            int mid = (l + r) / 2;
            build(2 * pos + 1, l, mid);
            build(2 * pos + 2, mid + 1, r);
            seg[pos] = max(seg[2 * pos + 1], seg[2 * pos + 2]);
        };

        // Query for the leftmost basket index with capacity >= X.
        function<int(int, int, int, int)> query = [&](int pos, int l, int r, int X) -> int {
            if(seg[pos] < X) return -1; // No basket in this segment is sufficient.
            if(l == r) return l;        // Found the basket.
            int mid = (l + r) / 2;
            int leftAns = query(2 * pos + 1, l, mid, X);
            if(leftAns != -1) return leftAns;
            return query(2 * pos + 2, mid + 1, r, X);
        };

        // Update the segment tree when a basket is used.
        function<void(int, int, int, int, int)> update = [&](int pos, int l, int r, int index, int val) {
            if(l == r) {
                seg[pos] = val;
                return;
            }
            int mid = (l + r) / 2;
            if(index <= mid)
                update(2 * pos + 1, l, mid, index, val);
            else
                update(2 * pos + 2, mid + 1, r, index, val);
            seg[pos] = max(seg[2 * pos + 1], seg[2 * pos + 2]);
        };

        build(0, 0, n - 1);
        int unplaced = 0;

        // Process each fruit in order.
        for (int i = 0; i < n; i++) {
            int basketIndex = query(0, 0, n - 1, fruits[i]);
            if(basketIndex == -1) {
                // No available basket can hold this fruit.
                unplaced++;
            } else {
                // Mark the basket as used by setting its capacity to -1.
                update(0, 0, n - 1, basketIndex, -1);
            }
        }
        return unplaced;
    }
};

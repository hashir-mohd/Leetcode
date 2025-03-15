#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        if (n == 0) return fruits.size(); // Handle edge case, though n >=1 per constraints
        
        vector<int> tree(4 * n);
        build(1, 0, n-1, baskets, tree);
        
        int unplaced = 0;
        
        for (int q : fruits) {
            int idx = query(1, 0, n-1, q, tree);
            if (idx == -1) {
                unplaced++;
            } else {
                update(1, 0, n-1, idx, 0, tree);
            }
        }
        
        return unplaced;
    }

private:
    void build(int node, int l, int r, const vector<int>& arr, vector<int>& tree) {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid, arr, tree);
        build(2 * node + 1, mid + 1, r, arr, tree);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int l, int r, int x, vector<int>& tree) {
        if (tree[node] < x) {
            return -1;
        }
        if (l == r) {
            return l;
        }
        int mid = (l + r) / 2;
        int left_res = query(2 * node, l, mid, x, tree);
        if (left_res != -1) {
            return left_res;
        }
        int right_res = query(2 * node + 1, mid + 1, r, x, tree);
        return right_res;
    }

    void update(int node, int l, int r, int idx, int val, vector<int>& tree) {
        if (l == r) {
            tree[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) {
            update(2 * node, l, mid, idx, val, tree);
        } else {
            update(2 * node + 1, mid + 1, r, idx, val, tree);
        }
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
};
#include <vector>
#include <set>
#include <algorithm>
#include <map>

const int MAX_VAL_SIEVE = 100001;
std::vector<bool> is_prime_sieve(MAX_VAL_SIEVE, true);
bool sieve_computed = false;

void ensure_sieve() {
    if (sieve_computed) return;
    if (MAX_VAL_SIEVE > 0) is_prime_sieve[0] = false;
    if (MAX_VAL_SIEVE > 1) is_prime_sieve[1] = false;
    for (int p = 2; p * p < MAX_VAL_SIEVE; ++p) {
        if (is_prime_sieve[p]) {
            for (int i = p * p; i < MAX_VAL_SIEVE; i += p)
                is_prime_sieve[i] = false;
        }
    }
    sieve_computed = true;
}

bool check_prime(int n) {
    if (n < 0 || n >= MAX_VAL_SIEVE) return false;
    return is_prime_sieve[n];
}

struct SegTreeNode {
    int max_val;
    int lazy;
};

std::vector<SegTreeNode> tree;
int N_seg; // Number of elements in the conceptual array S (n-1)

void build_seg_tree(int node, int start, int end) {
    tree[node] = {0, 0}; // Max val 0, lazy 0
    if (start == end) return;
    int mid = (start + end) / 2;
    build_seg_tree(2 * node, start, mid);
    build_seg_tree(2 * node + 1, mid + 1, end);
}

void push(int node) {
    if (tree[node].lazy != 0) {
        tree[2 * node].max_val += tree[node].lazy;
        tree[2 * node].lazy += tree[node].lazy;
        tree[2 * node + 1].max_val += tree[node].lazy;
        tree[2 * node + 1].lazy += tree[node].lazy;
        tree[node].lazy = 0;
    }
}

void update_range_seg_tree(int node, int start, int end, int l, int r, int val) {
    if (start > end || start > r || end < l) return;
    if (l <= start && end <= r) {
        tree[node].max_val += val;
        tree[node].lazy += val;
        return;
    }
    push(node);
    int mid = (start + end) / 2;
    update_range_seg_tree(2 * node, start, mid, l, r, val);
    update_range_seg_tree(2 * node + 1, mid + 1, end, l, r, val);
    tree[node].max_val = std::max(tree[2 * node].max_val, tree[2 * node + 1].max_val);
}

int query_max_seg_tree(int node, int start, int end, int l, int r) {
    if (start > end || start > r || end < l) return -1e9; // Large negative
    if (l <= start && end <= r) return tree[node].max_val;
    push(node);
    int mid = (start + end) / 2;
    int p1 = query_max_seg_tree(2 * node, start, mid, l, r);
    int p2 = query_max_seg_tree(2 * node + 1, mid + 1, end, l, r);
    return std::max(p1, p2);
}


class Solution {
public:
    std::vector<std::set<int>> prime_occurrences;

    void update_prime_contribution(int p_val, int n_elements, bool add) {
        if (prime_occurrences[p_val].empty()) return;
        
        int first_idx = *prime_occurrences[p_val].begin();
        int last_idx = *prime_occurrences[p_val].rbegin();
        int val_change = add ? 1 : -1;

        // Contribution to L(s+1) for s in [first_idx, n_elements-1]
        // n_elements is (n-1) from main, which is N_seg. Max index is N_seg-1.
        // Corresponds to k-1 in [first_idx, n-2] (original problem n)
        // Max index for segment tree is N_seg-1.
        if (first_idx <= N_seg - 1) {
             update_range_seg_tree(1, 0, N_seg - 1, first_idx, N_seg - 1, val_change);
        }

        // Contribution to R(s+1) for s in [0, last_idx-1]
        // Corresponds to k-1 in [0, last_idx-1]
        if (last_idx - 1 >= 0) {
            update_range_seg_tree(1, 0, N_seg - 1, 0, last_idx - 1, val_change);
        }
    }

    vector<int> maximumCount(vector<int>& nums, vector<vector<int>>& queries) {
        ensure_sieve();
        int n = nums.size();
        if (n < 2) return {}; // Should not happen based on constraints

        N_seg = n - 1; // Number of split points k-1, so indices 0 to n-2
        if (N_seg <= 0) { // e.g. n=1, though constraints say n>=2
             std::vector<int> results(queries.size(), 0);
             return results;
        }

        tree.assign(4 * N_seg, {0, 0});
        build_seg_tree(1, 0, N_seg - 1);
        
        prime_occurrences.assign(MAX_VAL_SIEVE, std::set<int>());

        for (int i = 0; i < n; ++i) {
            if (check_prime(nums[i])) {
                prime_occurrences[nums[i]].insert(i);
            }
        }

        for (int p = 0; p < MAX_VAL_SIEVE; ++p) {
            if (check_prime(p) && !prime_occurrences[p].empty()) {
                update_prime_contribution(p, N_seg, true);
            }
        }

        std::vector<int> results;
        results.reserve(queries.size());

        for (const auto& query : queries) {
            int idx = query[0];
            int new_val = query[1];
            int old_val = nums[idx];

            // --- Handle old_val ---
            if (check_prime(old_val)) {
                update_prime_contribution(old_val, N_seg, false); // Undo old
                prime_occurrences[old_val].erase(idx);
                if (!prime_occurrences[old_val].empty()) { // If still exists
                    update_prime_contribution(old_val, N_seg, true); // Add new
                }
            }
            
            nums[idx] = new_val;

            // --- Handle new_val ---
            if (check_prime(new_val)) {
                if (!prime_occurrences[new_val].empty()) { // If it existed elsewhere
                     update_prime_contribution(new_val, N_seg, false); // Undo old state of new_val
                }
                prime_occurrences[new_val].insert(idx);
                update_prime_contribution(new_val, N_seg, true); // Add new state of new_val
            }
            
            if (N_seg > 0) {
                 results.push_back(query_max_seg_tree(1, 0, N_seg - 1, 0, N_seg - 1));
            } else { // Should not be reached if n>=2
                 results.push_back(0);
            }
        }
        return results;
    }
};

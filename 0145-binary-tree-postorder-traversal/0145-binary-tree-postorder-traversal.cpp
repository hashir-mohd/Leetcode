/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root, vector<int>& res) {
        vector<int> postorder;

        if (root == NULL) {
            return;
        }

        stack<TreeNode*> st1, st2;

        st1.push(root);

        while (!st1.empty()) {
            root = st1.top();
            st1.pop();

            st2.push(root);
            res.push_back(root->val);
            if (root->left != NULL) {
                st1.push(root->left);
            }
            if (root->right != NULL) {
                st1.push(root->right);
            }
        }
        while (!st2.empty()) {
            postorder.push_back(st2.top()->val);
            st2.pop();
        }
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        reverse(res.begin(), res.end());
        return res;
    }
};
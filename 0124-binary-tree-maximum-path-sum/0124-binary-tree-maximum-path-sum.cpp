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
    int helper(TreeNode* root, int& dia) {
        if (root == nullptr)
            return 0;
        int lh = helper(root->left, dia);
        int rh = helper(root->right, dia);
        dia=max(dia,root->val);
        dia=max(dia,root->val+lh);
        dia=max(dia,root->val+rh);
        dia = max(dia, root->val+lh + rh);
        return max(root->val , max(lh+root->val, rh+root->val));
    }
    int maxPathSum(TreeNode* root) {
        int dia = INT_MIN;
        helper(root, dia);
        
        return dia;
    }
};
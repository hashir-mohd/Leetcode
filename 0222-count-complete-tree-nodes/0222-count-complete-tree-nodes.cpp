/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void helper(TreeNode* root){
        if(root == nullptr) return;
        count++;
        helper(root->left);
        helper(root->right);
    }
public:
    int count =0;
    int countNodes(TreeNode* root) {
        helper(root);
        return count;
    }
};
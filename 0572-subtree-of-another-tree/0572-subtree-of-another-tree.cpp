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

    bool preorder(TreeNode* root,TreeNode* subRoot){
    if(root == nullptr){
        return false;
    }
    if(isSameTree(root, subRoot)){
        return true;
    }
   return preorder(root->left, subRoot) || preorder(root->right, subRoot);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr)return true;
        if(p == nullptr || q == nullptr) return false; 

        if(p->val!=q->val)return false;
        return   isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return preorder(root,subRoot);
    }
};
class Solution {
    int height(TreeNode* root){
        if(root==nullptr)return 0;
        return 1+ max(height(root->left),height(root->right));
    }

    TreeNode* helper(TreeNode* root){
        int lh=height(root->left);
        int rh=height(root->right);
        if(lh==rh){
            return root;
        }
        if(lh>rh)return helper(root->left);
        else return helper(root->right);
        
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return helper(root);
        
    }
};
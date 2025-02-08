
class Solution {
public:
    int helper(TreeNode* root,int &dia){
        if(root==nullptr)return 0;
        int lh= helper(root->left,dia);
        int rh= helper(root->right,dia);
        dia=max(dia,lh+rh);
        return 1+max(lh,rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
        helper(root,dia);
        return dia;
    }
};
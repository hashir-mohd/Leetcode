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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL) return res;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while(curr != nullptr){
            st.push(curr);
            curr=curr->left;
        }
        while(!st.empty()){
            TreeNode* temp=st.top();
            st.pop();
            res.push_back(temp->val);
            
                temp=temp->right;
            
            while(temp!= nullptr){
                st.push(temp);
                cout<< temp->val <<endl;
                temp=temp->left;
                
            }
        }
        return res;
    }
};
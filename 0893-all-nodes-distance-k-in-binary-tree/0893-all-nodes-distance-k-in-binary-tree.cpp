/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void markParents(TreeNode* root,unordered_map<TreeNode*, TreeNode*> &parents_track,TreeNode* target){
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current= q.front();
            q.pop();
            if(current->left){
                q.push(current->left);
                parents_track[current->left]=current;
            }
            if(current->right){
                q.push(current->right);
                parents_track[current->right]=current;
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map <TreeNode*,TreeNode*> parents_track;
        markParents(root,parents_track,target);
        unordered_map<TreeNode*,bool> visited;
        queue <TreeNode*> q;
        q.push(target);
        visited[target]= true;
        int currLevel=0;
        while(!q.empty()){
            int size=q.size();
            if(currLevel++ == k) break;
            for(int i =0; i< size; i++){
                TreeNode* curr= q.front();
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left]= true;
                }
                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right]= true;
                }
                if(parents_track[curr] && !visited[parents_track[curr]]){
                    q.push(parents_track[curr]);
                    visited[parents_track[curr]]= true;
                }
            q.pop();
            }
        }
        vector<int> res;
        while(!q.empty()){
            TreeNode* curr= q.front();
            q.pop();
            res.push_back(curr->val);
        }
        return res;
    }
};
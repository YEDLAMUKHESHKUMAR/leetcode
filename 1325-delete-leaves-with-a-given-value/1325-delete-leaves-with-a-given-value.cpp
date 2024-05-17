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
    void solve(TreeNode* root,int target,TreeNode* prev){
        if(root == NULL) return ;
        solve(root->left,target,root);
        solve(root->right,target,root);
        if(root->left == NULL && root->right == NULL){
            if(root->val == target){
                if( prev->left == root){
                    prev->left = NULL;
                }
                else{
                    prev->right = NULL;
                }
            }
        }
        
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        solve(root,target,root);
        if(root!=NULL && root->left == NULL && root->right == NULL && root->val == target) {
            return NULL;
        }
        return root;
    }
};
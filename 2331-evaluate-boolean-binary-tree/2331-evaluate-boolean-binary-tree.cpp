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
    bool solve(TreeNode* root){
        if(root == NULL) return true;
        bool left = solve(root->left);         // notes 
        bool right = solve(root->right);
        if(root->left != NULL && root->right != NULL){
            if(root->val == 2){
                return left | right;       // :)
            }
            else return left & right;
        }
        else return root->val;
    }



    bool evaluateTree(TreeNode* root) {
        return solve(root);
    }
};
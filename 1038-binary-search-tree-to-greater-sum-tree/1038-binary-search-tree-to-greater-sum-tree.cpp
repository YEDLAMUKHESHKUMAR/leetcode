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
    int sum = 0;
    TreeNode* solve(TreeNode* root){
        if(root == NULL) return NULL;
        solve(root->right);
        sum+=root->val;
        root->val = sum;
        solve(root->left);
        return root;
    }
    TreeNode* bstToGst(TreeNode* root) {
        return solve(root);
    }
};
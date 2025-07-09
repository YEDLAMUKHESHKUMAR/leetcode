// Last updated: 7/9/2025, 9:14:14 PM
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

    int solve(TreeNode* root, int& maxi){
        if(root == NULL) return 0;

        int left = solve(root->left, maxi);
        int right = solve(root->right, maxi);
        int rval = root->val;
        int lval = -10000, rival = -10000;
        if(root->left != NULL) lval = root->left->val;
        if(root->right != NULL) rival = root->right->val;
        // cout<<rval<<" "<<lval<<" "<<rival<<" lr"<<left<<" "<<right<<endl;
        if(rval == lval && rval == rival) {
            int longest = 1 + max(left, right);
            maxi = max(maxi, left + right + 1 );
            return longest;
        }
        if(rval == lval) {
            maxi = max(maxi, 1 + left);
            return 1 + left;
        }
        if(rval == rival){
            maxi = max(maxi, 1 + right);
            return 1 + right;
        } 

        return 1;
    }
    int longestUnivaluePath(TreeNode* root) {
        int maxi = 1;
        solve(root, maxi);
        return maxi - 1;
    }
};
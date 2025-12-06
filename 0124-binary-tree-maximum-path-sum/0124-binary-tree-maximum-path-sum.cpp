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
    int solve(TreeNode* root, int& ans){
        if(root == NULL) return 0;

        int leftMaxSum = solve(root->left, ans);
        int rightMaxSum = solve(root->right, ans);

        ans = max({ans, root->val + leftMaxSum + rightMaxSum,root->val + leftMaxSum, root->val + rightMaxSum, root->val });
        return  max({root->val + leftMaxSum, root->val + rightMaxSum, root->val});


    }
    int maxPathSum(TreeNode* root) {
        int ans = -1e8;
        solve(root, ans);
        return ans;
    }
};
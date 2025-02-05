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
 #define ll long long
class Solution {
public:
    bool ans = true;
    pair<ll,ll> solve(TreeNode* root){
        if(root == NULL) return {LLONG_MAX, LLONG_MIN};
        auto left = solve(root->left);
        auto right = solve(root->right);
        ll leftMin = left.first, leftMax= left.second, rightMin = right.first, rightMax = right.second;
        if(root->val <= leftMax || root->val >= rightMin) ans = false;
        return { min({leftMin, rightMin,1LL * root->val}), max({leftMax, rightMax,1LL * root->val}) };

    }
    bool isValidBST(TreeNode* root) {
        // brute force : take an array , make inorder traversal and store elements in it . The array elements should be in increasing order , if not return false
        solve(root);
        return ans;

        
    }
};
// Last updated: 7/30/2025, 10:59:53 PM
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
    int maxi = 0;
    vector<int> solve(TreeNode* root){
        if(root == NULL) return {0, 1, INT_MAX, INT_MIN };

        vector<int> left = solve(root->left);
        vector<int> right = solve(root->right);
        int sum1 = left[0], isBST1 = left[1], leftMin = left[2] , leftMax = left[3] ;
        int sum2 = right[0], isBST2 = right[1], rightMin = right[2] , rightMax = right[3] ;
        if(isBST1 == false || isBST2 == false ||  root->val <= leftMax || root->val >= rightMin ){
            return {0,0,0,0};
        }
        else{
            maxi = max(maxi, sum1 + sum2 + root->val);
            return {sum1 + sum2 + root->val, 1,  min({root->val, leftMin, rightMin}), max({root->val, leftMax, rightMax })  };
        }



    }
    int maxSumBST(TreeNode* root) {
        // unordered_map<TreeNode*, vector<int>> mp;
        solve(root);
        return maxi;

    }
};
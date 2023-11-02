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
    pair<int,int> postOrder(TreeNode* node, int &ans){
        if(node==NULL){
            return {0,0};
        }
        auto [left_sum , left_count] = postOrder(node->left,ans);
        auto [right_sum , right_count] = postOrder(node->right,ans);
        int curr_sum = node->val + left_sum + right_sum ;
        int curr_count = 1 + left_count + right_count ;
        if(curr_sum / curr_count == node->val) ans++;
        return {curr_sum , curr_count};
    }
    int averageOfSubtree(TreeNode* root) {
        // I have been stuck in this problem at one thing , i.e. I can't figure it out how to store
        // both sum and count at a time 
        int ans = 0;
        postOrder(root,ans);
        return ans ;
    }
};
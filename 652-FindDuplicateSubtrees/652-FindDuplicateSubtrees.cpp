// Last updated: 8/10/2025, 3:51:24 PM
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
    string solve(TreeNode* root, unordered_map<string,int>& mp, unordered_map<string,int>& vis, vector<TreeNode*>& ans ){
        if(root == NULL) return ".N.";

        string left = solve(root->left, mp, vis, ans);
        string right = solve(root->right, mp, vis, ans);

        string s = left + "." + right + "." + to_string(root->val) + ".";
        mp[s]++;
        if(!vis[s] && mp[s] > 1){
            vis[s] = 1;
            ans.push_back(root);
        }
        return s;

    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int> mp;
        unordered_map<string,int> vis;
        vector<TreeNode*> ans;
        solve(root, mp, vis, ans);
        return ans;
        

    }
};
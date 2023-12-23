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
    void solve(int i,int level,TreeNode* root,map<int,map<int,multiset<int>>> &mp){
        if(root==NULL){
            return;
        }
        mp[i][level].insert(root->val);
        solve(i-1,level+1,root->left,mp);
        solve(i+1,level+1,root->right,mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;
        solve(0,0,root,mp);
        vector<vector<int>> ans;
        for(auto i:mp){
            vector<int> col;
            for(auto j:i.second){
                col.insert(col.end(),j.second.begin(),j.second.end());
            }
            ans.push_back(col);
        }
        return ans;        
    }
};
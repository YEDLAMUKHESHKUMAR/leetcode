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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        stack<TreeNode*> s;
        vector<int> ans;
        // s.push(root);
        while(true){
            if(root!=NULL){
                s.push(root);
                root=root->left;
            }
            else{
                if(s.empty()) break;
                root = s.top();
                s.pop();
                int currData = root->val;
                ans.push_back(currData);
                // s.push(root);
                root=root->right;
                
            }
        }
        return ans;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans = NULL;
    bool flag = false;
    bool solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return false;
        if(flag == true) return true;
        
        bool left =  solve(root->left, p , q) ;
        bool right =  solve(root->right, p , q) ;
        if(flag ) return true;
        if(left == true && right == true) {
            ans = root; flag = true;
            // return true;
        }
        else if((left || right) && (root->val == p->val || root->val == q->val)){
            ans = root ; flag = true;
        }
        return root->val == p->val || root->val == q->val || left | right;

        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        solve(root, p, q);
        return ans;
    }
};
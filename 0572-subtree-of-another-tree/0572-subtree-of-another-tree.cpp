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
    bool solve(TreeNode* root,TreeNode* subRoot){
        if(root==NULL && subRoot==NULL) return true;       // :) can handle duplicates 
        if(root==NULL || subRoot==NULL){
            if(root!=NULL) return false;
            if(subRoot!=NULL) return false;
        }
        if(root->val != subRoot->val) return false;
        bool left  =  solve(root->left,subRoot->left);
        bool right  =  solve(root->right,subRoot->right);
        if(left==true && right == true) return true;
        return false;
    }
    bool inorder(TreeNode* root, TreeNode* subRoot){
        if(root==NULL) return false;
        if(root->val == subRoot->val){
            if(solve(root,subRoot) == true) return true;
        } 
        if(inorder(root->left,subRoot) == true) return true;
        if(inorder(root->right,subRoot)== true) return true;
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return inorder(root,subRoot);
    }
};
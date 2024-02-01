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
    TreeNode* solve(vector<int> &preorder, int preStart , int preEnd,vector<int> &inorder, int inStart, int inEnd,map<int,int> &mp){
        if(preStart > preEnd || inStart > inEnd){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);  // make root as curr Preorder element ; 
        int inRoot = mp[root->val];  // find curr preorder element in inorder ..
        int numsLeft = inRoot - inStart; // after finding the position , find no of elements on left side
        root->left = solve(preorder,preStart + 1 , preStart + numsLeft,inorder,inStart,inRoot - 1 , mp);
        root->right = solve(preorder,preStart + numsLeft + 1,preEnd ,inorder,inRoot + 1 ,inEnd , mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {    // striver
        map<int,int> mp;
        int n = preorder.size();
        int m = inorder.size();
        for(int i=0;i<m;i++){
            mp[inorder[i]] = i;
        }
        TreeNode* root = solve(preorder,0,n-1,inorder,0,m-1,mp);
        return root;
    }
};
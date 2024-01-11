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
    int widthOfBinaryTree(TreeNode* root) {
        // notes 
        if(root==NULL){
            return 0;
        }
        queue<pair<TreeNode* , unsigned long long int>> q;
        q.push(make_pair(root,0));
        int maxWidth = 0;
        while(!q.empty()){
            unsigned long long int left = q.front().second , right = 0 ;
            unsigned long long int n = q.size();
            for(unsigned long long int i=0; i<n; i++){
                pair<TreeNode* , unsigned long long int > p = q.front();
                q.pop();
                TreeNode* curr = p.first;
                right = p.second;
                if(curr->left!=NULL){
                    q.push(make_pair(curr->left, 2 * right + 1)); // creating next index for left child
                }
                if(curr->right!=NULL){
                    q.push(make_pair(curr->right , 2 * right + 2 )); // creating next index for right child
                }
            }
            maxWidth = max(int(right - left + 1 ), maxWidth); // change it to int again


        }
        return maxWidth;

    }
};
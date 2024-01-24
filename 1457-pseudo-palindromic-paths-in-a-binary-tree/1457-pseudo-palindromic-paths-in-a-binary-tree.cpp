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
    int solve(TreeNode* root , unordered_map<int,int> &v){
        if(root==NULL){                // :)  
            return 0;
        }
        v[root->val]++;
        int ans = 0;
        if(root->left == NULL && root->right == NULL){
            int odd = 0;
            for(auto i:v){      //   TLE :  my bad i made loop to run 10 times everytime                 
                if(i.second % 2 != 0)  
                {
                    odd++;
                }
            }
            if(odd <= 1 ) {   // there should be only one odd or 0 odd freq , for eg: 666 or 656
                ans = 1 ;
                // return 0;
            }
            
        }
        int left = solve(root->left,v);
        int right = solve(root->right,v);
        v[root->val]--;
        return left+ right + ans;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        // vector<int> v(10,0);
        unordered_map<int,int> v;
        return solve(root,v);
    }
};
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
    TreeNode* st = NULL;
    unordered_map<TreeNode*, TreeNode*> par;
    void createGraph(TreeNode* root , TreeNode* parent , int start  ){
        if(root == NULL){
            return;
        }
        if(root->val == start ){
            st = root ;
        }
        par[root] = parent ; 
        createGraph(root->left, root , start);
        createGraph(root->right, root , start);
    }
    int amountOfTime(TreeNode* root, int start) {
        createGraph(root,NULL,start);
        queue<TreeNode*> q;
        unordered_set<TreeNode*> vis;  
        q.push(st);
        int time = -1;
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                auto curr = q.front();
                q.pop();
                vis.insert(curr);
                if(curr->left!= NULL && vis.count(curr->left)==0){  // visiting all adjacents
                    q.push(curr->left);
                }
                if(curr->right!= NULL && vis.count(curr->right)==0){  // visiting all adjacents
                    q.push(curr->right);
                }
                if(par[curr]!= NULL && vis.count(par[curr]) == 0 ) {
                    q.push(par[curr]);
                }
            }
            time++;
        }
        return time;
        
    }
};
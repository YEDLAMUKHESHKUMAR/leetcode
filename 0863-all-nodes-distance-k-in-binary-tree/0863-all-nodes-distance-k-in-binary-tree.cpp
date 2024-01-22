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
    void makeParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &mp){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left != NULL ){
                mp[curr->left] = curr ; // assigining parent to child , used for back traversal
                q.push(curr->left);
            }
            if(curr->right != NULL){
                mp[curr->right] = curr;
                q.push(curr->right);
            }
        }

        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        makeParent(root,parent);
        queue<TreeNode*> queue;
        unordered_map<TreeNode*,bool> visited ; 
        queue.push(target); // start from your target node
        visited[target] = true ;
        vector<int> ans;
        int curr_level = 0 ;
        while(!queue.empty()){
            int n = queue.size();
            if(curr_level == k ) break;
            curr_level++;
            for(int i=0;i<n;i++){
                TreeNode* curr = queue.front();
                queue.pop();
                if(curr->left != NULL && visited[curr->left] == false){
                    queue.push(curr->left);
                    visited[curr->left] = true;
                }
                if(curr->right!=NULL && visited[curr->right] == false){
                    queue.push(curr->right);
                    visited[curr->right] = true;
                }
                if(parent[curr] && visited[parent[curr]] == false){
                    queue.push(parent[curr]);
                    visited[parent[curr]] = true;
                }
            }
            // k--;
            // if(k==0) break;
        }
        while(!queue.empty()){
            ans.push_back(queue.front()->val);
            queue.pop();
        }
        return ans;
    }
};
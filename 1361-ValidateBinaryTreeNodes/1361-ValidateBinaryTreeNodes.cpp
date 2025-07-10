// Last updated: 7/10/2025, 6:28:22 PM
class Solution {
public:
    bool solve(int i, vector<int>& left, vector<int>& right, vector<int>& vis, int& nodes){
        vis[i] = true;
        nodes++;
        if(left[i] != -1 ){
            if(vis[left[i]]) return false;
            if(solve( left[i], left, right, vis, nodes) == false) return false;

        }
        if(right[i] != -1){
            if(vis[right[i]]) return false;
            if(solve(right[i], left, right, vis, nodes) == false) return false;
        }
        return true;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        for(int i = 0 ; i < n ;i++){
            vector<int> vis(n + 1, 0);
            if(!vis[i]){
                int nodes = 0;
                bool res = solve(i, leftChild, rightChild, vis, nodes);
                if(nodes == n && res ) return true;
                if(res == false) return false;
            }
        }
        return false;
    }
};
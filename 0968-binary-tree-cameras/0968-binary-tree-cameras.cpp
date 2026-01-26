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
    int installMinimumNumberOfCameras(TreeNode* root, int& minimumCamerasUsed){
        if(root == NULL) return 2;
        int left = installMinimumNumberOfCameras(root->left, minimumCamerasUsed);
        int right = installMinimumNumberOfCameras(root->right, minimumCamerasUsed);

        bool camRemoved = false;
        if(left == 2 && right == 2){
            minimumCamerasUsed++;
            return 1;
        }

        if(left == 1) {
            camRemoved = true;
            minimumCamerasUsed--;
        }
        if(right == 1){
            camRemoved = true;
            minimumCamerasUsed--;
        }
        if(camRemoved){
            minimumCamerasUsed++;
            return 0;
        }
        if(left == 0 || right == 0){
            return 2;
        }
        return 560;

    }
    int minCameraCover(TreeNode* root) {
        if(root->left == NULL && root->right == NULL) return 1;

        int minimumCamerasUsed = 0;
        int dontKeepCamera = installMinimumNumberOfCameras(root, minimumCamerasUsed );
        // if(dontKeepCamera) minimumCamerasUsed--;
        return minimumCamerasUsed;
    }
};
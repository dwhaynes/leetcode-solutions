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
    int count = 0;
    enum class Camera {hasCamera, covered, needsCover};
    Camera cover(TreeNode* root){
        if(!root) return Camera::covered;
        Camera left = cover(root->left);
        Camera right = cover(root->right);

        if(left == Camera::needsCover || right == Camera::needsCover){
            count++;
            return Camera::hasCamera;
        }
        if(left == Camera::hasCamera || right == Camera::hasCamera) return Camera::covered;
        return Camera::needsCover;
    }
public:
    int minCameraCover(TreeNode* root) {
        return cover(root) == Camera::needsCover ? ++count : count;
    }
};
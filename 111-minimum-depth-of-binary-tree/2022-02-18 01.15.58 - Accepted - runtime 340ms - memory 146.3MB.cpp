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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if(!root->left && !root->right) return 1;
        int min_depth = INT_MAX;
        if(root->left) min_depth = min(min_depth, minDepth(root->left));
        if(root->right) min_depth = min(min_depth, minDepth(root->right));
        return min_depth+1;
    }
};
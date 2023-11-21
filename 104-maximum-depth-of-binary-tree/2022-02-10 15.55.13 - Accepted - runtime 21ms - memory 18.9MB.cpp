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
    int depth = 1;
    void dfs(TreeNode* root, int l = 1){
        if (!root) return;
        if (l > depth) depth = l;
        dfs(root->left,l+1);
        dfs(root->right,l+1);
    }
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        dfs(root);
        return depth;
    }
};
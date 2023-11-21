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
     bool dfs(TreeNode* root){
         if(!root) return false;
         if(!root->left && !root->right && root->val) return true;
         bool left = dfs(root->left);
         bool right = dfs(root->right);
         if(!left) root->left = nullptr;
         if(!right) root->right = nullptr;
         return left || right || root->val;
     }
public:
    TreeNode* pruneTree(TreeNode* root) {
        dfs(root);
        if(root->val == 0 && !root->left && !root->right) return nullptr;
        return root;
    }
};
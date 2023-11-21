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
    TreeNode* helper(TreeNode* root){
        if(!root) return nullptr;
        auto left = helper(root->left);
        auto right = helper(root->right);
        root->right = left;
        root->left = nullptr;
        TreeNode *curr = root;
        while(curr && curr->right) curr = curr->right;
        curr->right = right;
        return root;
    }
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        helper(root);
    }
};
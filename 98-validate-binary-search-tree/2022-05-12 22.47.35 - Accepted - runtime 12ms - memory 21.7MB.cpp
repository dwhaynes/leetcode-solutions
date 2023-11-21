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
    bool validate(TreeNode* root, TreeNode* low, TreeNode* high){
        if(!root) return true;
        if((low && root->val <= low->val) || (high && root->val >= high->val)) return false;
        return validate(root->right,root,high) && validate(root->left, low, root);
    }
public:
    bool isValidBST(TreeNode* root) {
        return validate(root,nullptr,nullptr);
    }
};
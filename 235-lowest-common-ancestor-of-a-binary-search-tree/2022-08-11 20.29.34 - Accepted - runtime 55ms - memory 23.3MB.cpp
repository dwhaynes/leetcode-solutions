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
    TreeNode* ans = nullptr;
    bool helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return false;
        int left = helper(root->left,p,q) ? 1 : 0;
        int right = helper(root->right,p,q) ? 1 : 0;
        int mid = (root == p || root == q || p == q) ? 1 : 0;
        if(left + right + mid >= 2) ans = root;
        return (left + right + mid >= 1);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root,p,q);
        return ans;
    }
};
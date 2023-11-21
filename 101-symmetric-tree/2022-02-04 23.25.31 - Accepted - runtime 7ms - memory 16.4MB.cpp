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
    bool isMirror(TreeNode* T1, TreeNode* T2){
        if(!T1 && !T2) return true;
        if(!T1 || !T2) return false;
        return (T1->val == T2->val) &&
            isMirror(T1->right, T2->left) &&
            isMirror(T1->left, T2->right);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root,root);
    }
};
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
    bool search(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return false;
        int left = search(root->left,p,q) ? 1 : 0;
        int right = search(root->right,p,q) ? 1 : 0;
        int mid = (root == p || root == q);
        if(left + mid + right >= 2) ans = root;
        return (left || mid || right);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        search(root,p,q);
        return ans;
    }
};
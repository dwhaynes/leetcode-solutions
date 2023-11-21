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
    string tree2str(TreeNode* root) {
        if(!root) return "";
        stringstream ans;
        ans << root->val;
        if(!root->right && !root->left) return ans.str();
        if(!root->right) {
            ans << "(" + tree2str(root->left) + ")";
            return ans.str();
        }
        ans << "(" + tree2str(root->left) + ")";
        ans << "(" + tree2str(root->right) + ")";
        return ans.str();
    }
};
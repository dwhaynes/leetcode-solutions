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
    vector<int> tree = vector<int>(100,-101);
    void helper(TreeNode* root, int row = 0){
        if(!root) return;
        helper(root->left,row+1);
        tree[row] = root->val;
        helper(root->right,row+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        helper(root);
        auto it = remove(tree.begin(),tree.end(),-101);
        tree.erase(it,tree.end());
        return tree;
    }
};
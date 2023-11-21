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
    vector<vector<int>> tree;
    vector<int> ans;
    void helper(TreeNode* root, int row = 0){
        if(!root) return;
        helper(root->left,row+1);
        while(row >= tree.size()) tree.push_back({});
        tree[row].push_back(root->val);
        helper(root->right,row+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        helper(root);
        for(auto row: tree){
            ans.push_back(row.back());
        }
        return ans;
    }
};
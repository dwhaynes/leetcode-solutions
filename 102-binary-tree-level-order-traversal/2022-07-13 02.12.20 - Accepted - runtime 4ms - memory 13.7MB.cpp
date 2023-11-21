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
    vector<vector<int>> ans;
    void helper(TreeNode* root, int depth){
        if(!root) return;
        if(depth == ans.size()) ans.push_back({});
        ans[depth].push_back(root->val);
        helper(root->left,depth+1);
        helper(root->right,depth+1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        helper(root,0);
        return ans;
    }
};
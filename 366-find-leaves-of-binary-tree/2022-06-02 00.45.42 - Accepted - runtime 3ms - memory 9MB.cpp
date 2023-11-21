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
    int dfs(TreeNode* root){
        if(!root) return -1;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int curr = max(left,right)+1;
        if(ans.size() == curr) ans.push_back({});
        ans[curr].push_back(root->val);
        return curr;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
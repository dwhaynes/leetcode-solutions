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
    vector<int> result;
    void dfs(TreeNode* head){
        if(!head) return;
        dfs(head->left);
        result.push_back(head->val);
        dfs(head->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return result;
    }
};
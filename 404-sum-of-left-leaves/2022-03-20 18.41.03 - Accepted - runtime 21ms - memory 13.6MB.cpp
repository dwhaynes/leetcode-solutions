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
    int dfs(TreeNode* root, bool isLeft){
        if(!root->left && !root->right) return isLeft ? root->val : 0;
        int sum = 0;
        if(root->left) sum+=dfs(root->left, true);
        if(root->right) sum+=dfs(root->right, false);
        return sum;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        return dfs(root, false);
    }
};
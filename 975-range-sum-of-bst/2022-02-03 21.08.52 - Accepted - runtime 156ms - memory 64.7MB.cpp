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
    int sum=0;
    int low;
    int high;
    void dfs(TreeNode* root){
        if (!root) return;
        if (root->val >= this->low && root->val <= this->high) sum+=root->val;
        if (low < root->val) dfs(root->left);
        if (high > root->val) dfs(root->right);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        this->low = low;
        this->high = high;
        dfs(root);
        return sum;
    }
};
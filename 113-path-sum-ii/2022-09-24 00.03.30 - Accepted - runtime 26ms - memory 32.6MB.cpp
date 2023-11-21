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
    void dfs(TreeNode* root, int targetSum, vector<int> path){
        if(!root->left && !root->right){
            if(targetSum == root->val){
                path.push_back(root->val);
                ans.push_back(path);
            }
            return;
        }
        path.push_back(root->val);
        int newTarget = targetSum-root->val;
        if(root->left) dfs(root->left,newTarget,path);
        if(root->right) dfs(root->right,newTarget,path);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        dfs(root,targetSum,{});
        return ans;
    }
};
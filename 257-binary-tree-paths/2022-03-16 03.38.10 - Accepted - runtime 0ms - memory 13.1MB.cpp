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
    vector<string> paths;
    void dfs(TreeNode* root, string path){
        path+=to_string(root->val);
        if(!root->left && !root->right){
            paths.push_back(path);
            return;
        }
        if(root->left) dfs(root->left,path + "->");
        if(root->right) dfs(root->right, path + "->");
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root,"");
        return paths;
    }
};
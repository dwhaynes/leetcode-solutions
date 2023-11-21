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
    string join(vector<int> path){
        int n = path.size();
        if(n == 0) return "";
        string ans = to_string(path[0]);
        for(int i = 1; i < n; i++){
            ans+= "->"+ to_string(path[i]);
        }
        return ans;
    }
    void dfs(TreeNode* root, vector<int> path){
        path.push_back(root->val);
        if(!root->left && !root->right){
            paths.push_back(join(path));
            return;
        }
        if(root->left) dfs(root->left,path);
        if(root->right) dfs(root->right, path);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root,{});
        return paths;
    }
};
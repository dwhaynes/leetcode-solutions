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
    struct helper{
        int height = 0;
        bool balanced = false;
    };
    helper treeHelper(TreeNode* root){
        if (!root) return {-1,true};
        
        auto left = treeHelper(root->left);
        if (!left.balanced) return {-1, false};
        auto right = treeHelper(root->right);
        if (!right.balanced) return {-1,false};
        
        if(abs(left.height - right.height) < 2)
            return {max(left.height,right.height)+1, true};
        
        return {-1, false};
    }
public:
    bool isBalanced(TreeNode* root) {
        return treeHelper(root).balanced;   
    }
};
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
    int count = 0;
    void preorder(TreeNode* node, int path){
        if(node){
            path ^= (1 << node->val);
            if(!node->left && !node->right){
                if((path & (path-1)) == 0) count++;
            }
        preorder(node->left,path);
        preorder(node->right,path);
        }
        
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        preorder(root,0);
        return count;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* node;
    void inorder(TreeNode* original, TreeNode* cloned, TreeNode* target){
        if(!original) return;
        inorder(original->left,cloned->left,target);
        if(original == target) node = cloned;
        inorder(original->right,cloned->right,target);
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        inorder(original,cloned,target);
        return node;
    }
};
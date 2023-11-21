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
    void traverse(TreeNode* root, int maxVal){
        if(!root) return;
        if(root->val >= maxVal) {
            count++;
        }
        traverse(root->left,max(maxVal,root->val));
        traverse(root->right,max(maxVal,root->val));
    }
public:
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        traverse(root,-10e4-1);
        return count;
    }
};
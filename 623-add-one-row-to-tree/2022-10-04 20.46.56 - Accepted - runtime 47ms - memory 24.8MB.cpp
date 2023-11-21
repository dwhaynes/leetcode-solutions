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
    void insert(int val, TreeNode* node, int depth, int n){
        if(!node) return;
        if(depth == n-1){
            TreeNode* t = node->left;
            node->left = new TreeNode(val);
            node->left->left = t;
            t = node->right;
            node->right = new TreeNode(val);
            node->right->right = t;
        }else{
            insert(val,node->left,depth+1,n);
            insert(val,node->right,depth+1,n);
        }
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* n = new TreeNode(val);
            n->left = root;
            return n;
        }
        insert(val,root,1,depth);
        return root;
    }
};
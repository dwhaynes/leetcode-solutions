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
    set<TreeNode*> grand;
    void search(TreeNode* root, TreeNode* parent, TreeNode* gparent){
        if(!root) return;
        if(gparent && gparent->val%2 == 0) grand.insert(root);
        if(root->left) search(root->left,root,parent);
        if(root->right) search(root->right,root,parent);
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        search(root,nullptr,nullptr);
        int sum = 0;
        for(auto node: grand)
            sum+=node->val;
        return sum;
    }
};
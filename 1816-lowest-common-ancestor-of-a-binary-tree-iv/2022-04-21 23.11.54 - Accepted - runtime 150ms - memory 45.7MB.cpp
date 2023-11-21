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
    //TreeNode* ans = nullptr;
    TreeNode* search(TreeNode* root, unordered_set<TreeNode*>& nodes){
        if (!root) return root;
        TreeNode* left = search(root->left,nodes);
        TreeNode* right = search(root->right,nodes);
        if (left && right) return root;
        if (nodes.find(root) != nodes.end()) return root;
        return left ? left : right;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        unordered_set<TreeNode*> nodeset(nodes.begin(),nodes.end());
        return search(root,nodeset);
    }
};
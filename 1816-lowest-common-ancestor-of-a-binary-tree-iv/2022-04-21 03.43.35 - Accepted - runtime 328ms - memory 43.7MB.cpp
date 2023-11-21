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
    TreeNode* ans = nullptr;
    bool search(TreeNode* root, vector<TreeNode*> &nodes){
        if(!root) return false;
        int left = search(root->left,nodes) ? 1 : 0;
        int right = search(root->right, nodes) ? 1 : 0;
        int mid = 0;
        for(TreeNode* p : nodes) if (p == root){ mid = 1; break;}
        if(left + mid + right >= 2) ans = root;
        return (left + mid + right);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        if(nodes.size() == 1) return nodes[0];
        search(root,nodes);
        return ans;
    }
};
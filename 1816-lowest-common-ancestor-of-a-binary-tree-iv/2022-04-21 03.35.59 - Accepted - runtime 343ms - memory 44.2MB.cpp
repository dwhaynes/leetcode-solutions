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
        bool left = search(root->left,nodes);
        bool right = search(root->right, nodes);
        bool mid = any_of(nodes.begin(),nodes.end(),[&root](TreeNode* p){
            return p == root;
        });
        if(left + mid + right >= 2) ans = root;
        return (left | mid | right);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        if(nodes.size() == 1) return nodes[0];
        search(root,nodes);
        return ans;
    }
};
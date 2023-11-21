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
    int recordedDepth = -1;
    bool isCousin = false;
    bool dfs(TreeNode* root, int depth, int x, int y){
        if(!root) return false;
        
        if(recordedDepth != -1 && depth > recordedDepth) return false;
        
        if(root->val == x || root->val == y){
            if(recordedDepth == -1) recordedDepth = depth;
            return recordedDepth == depth;
        }
        
        bool left = dfs(root->left, depth+1, x, y);
        bool right = dfs(root->right, depth+1, x, y);
        
        if(left && right && recordedDepth != depth+1) isCousin = true;
        return left || right;
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, 0, x, y);
        return isCousin;
    }
};
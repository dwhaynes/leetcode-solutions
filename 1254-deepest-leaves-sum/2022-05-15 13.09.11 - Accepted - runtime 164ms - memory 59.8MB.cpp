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
    int maxdepth = 0;
    int sum = 0;
    void search(TreeNode* root, int depth){
        if(!root) return;
        if(depth > maxdepth){
            maxdepth = depth;
            sum = root->val;
        }else if(depth == maxdepth){
            sum+=root->val;
        }
        search(root->left,depth+1);
        search(root->right, depth+1);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        search(root,0);
        return sum;
    }
};
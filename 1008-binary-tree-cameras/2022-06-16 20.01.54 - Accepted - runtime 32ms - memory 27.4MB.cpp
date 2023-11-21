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
    vector<int> solve(TreeNode* node){
        if(!node) return {0,0,99999};
        auto l = solve(node->left);
        auto r = solve(node->right);
        int ml12 = min(l[1],l[2]);
        int mr12 = min(r[1],r[2]);
        
        int d0 = l[1] + r[1];
        int d1 = min(l[2]+mr12,r[2]+ml12);
        int d2 = 1 + min(l[0],ml12) + min(r[0],mr12);
        return {d0,d1,d2};
    }
public:
    int minCameraCover(TreeNode* root) {
        auto ans = solve(root);
        return min(ans[1],ans[2]);
    }
};
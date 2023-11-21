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
    using v = vector<int>;
public:
    TreeNode* solve(int start_pre, int start_in, int end_in, v& preorder, v& inorder){
        if(start_in > end_in || start_pre > inorder.size()-1) return nullptr;
        TreeNode* node = new TreeNode(preorder[start_pre]);
        int index = 0;
        for(int i = start_in; i <= end_in; i++) if(node->val == inorder[i]) index = i;
        node->left = solve(start_pre+1,start_in,index-1,preorder,inorder);
        node->right = solve(start_pre + index - start_in +1, index+1, end_in, preorder,inorder);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(0,0,inorder.size()-1,preorder,inorder);
    }
};
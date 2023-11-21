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
    TreeNode* makeTree(vector<int>& nums, int l, int r){
        if(l > r) return nullptr;
        int m = l + (r-l)/2;
        TreeNode* head = new TreeNode(nums[m]);
        head->left = makeTree(nums,l,m-1);
        head->right = makeTree(nums,m+1,r);
        return head;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        TreeNode* root = makeTree(nums,0,nums.size()-1);
        return root;
    }
};
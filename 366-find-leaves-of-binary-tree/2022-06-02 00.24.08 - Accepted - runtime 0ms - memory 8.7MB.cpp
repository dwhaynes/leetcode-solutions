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
public:
    vector<pair<int,int>> pairs;
    int getHeight(TreeNode* root){
        if(!root) return -1;
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        int currHeight = max(leftHeight,rightHeight)+1;
        pairs.push_back({currHeight,root->val});
        return currHeight;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        getHeight(root);
        sort(pairs.begin(),pairs.end());
        
        int n = pairs.size(), height = 0, i = 0;
        
        vector<vector<int>> solution;
        
        while(i < n){
            vector<int> nums;
            while(i < n && pairs[i].first == height) nums.push_back(pairs[i++].second);
            solution.push_back(nums);
            height++;
        }
        
        return solution;
    }
};
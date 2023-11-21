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
    vector<vector<int>> levels;
    void helper(TreeNode* root, int depth){
        if(!root) return;
        if(depth == levels.size()) levels.push_back({});
        levels[depth].push_back(root->val);
        helper(root->left,depth+1);
        helper(root->right,depth+1);
    }
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root) return {};
        vector<double> ans;
        helper(root,0);
        for(auto level:levels){
            double avg = accumulate(level.begin(),level.end(),0.0);
            avg /= level.size();
            ans.push_back(avg);
        }
        return ans;
    }
};
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
    vector<int> vec;
    void traverse(TreeNode* root){
        if(!root) return;
        vec.push_back(root->val);
        traverse(root->left);
        traverse(root->right);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        set<int> s;
        traverse(root);
        sort(vec.begin(),vec.end());
        for(auto val: vec){
            if(s.find(k-val) != s.end()) return true;
            s.insert(val);
        }
        return false;
    }
};
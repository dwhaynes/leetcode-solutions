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
    using data  = pair<int,int>;
    map<int,vector<data>> tree;
    void search(TreeNode* head, int row, int col){
        if(!head) return;
        tree[col].push_back({row,head->val});
        search(head->left,row+1,col-1);
        search(head->right,row+1,col+1);
    }
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> result;
        search(root,0,0);
        for(auto kv: tree){
            sort(kv.second.begin(),kv.second.end(),[](data& a, data& b){
                return get<0>(a) < get<0>(b);
            });
            vector<int> temp;
            for(auto p: kv.second){
                temp.push_back(get<1>(p));
            }
            result.push_back(temp);
        }
        return result;
    }
};
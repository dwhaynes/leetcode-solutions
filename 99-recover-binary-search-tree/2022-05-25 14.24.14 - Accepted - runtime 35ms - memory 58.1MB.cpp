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
    vector<int> vals;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        vals.push_back(root->val);
        inorder(root->right);
    }
    
    tuple<int,int> findErrors(){
        bool foundFirst = false;
        int x, y;
        for(int i = 1; i < vals.size(); ++i){
            if(vals[i] < vals[i-1]){
                y = vals[i];
                if(!foundFirst){
                    x = vals[i-1];
                    foundFirst = true;
                }else{
                    break;
                }
            }
        }
        return {x,y};
    }
    
    void repair(TreeNode* root, int x, int y, int count){
        if(!root) return;
        if(root->val == x || root->val == y){
            root->val = root->val == x ? y : x;
            if(--count == 0) return;
        }
        
        repair(root->left,x,y,count);
        repair(root->right,x,y,count);
    }
    
    void recoverTree(TreeNode* root) {
        inorder(root);
        auto [x,y] = findErrors();
        repair(root,x,y,2);
    }
};
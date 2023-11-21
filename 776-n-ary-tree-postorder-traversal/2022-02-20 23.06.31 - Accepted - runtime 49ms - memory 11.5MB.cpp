/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    vector<int> result;
    void dfs(Node* root){
        if(!root) return;
        for(auto c: root->children) dfs(c);
        result.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        dfs(root);
        return result;
    }
};
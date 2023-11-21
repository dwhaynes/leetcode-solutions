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
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int>> levels;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                auto node = q.front();
                q.pop();
                level.push_back(node->val);
                for(auto child: node->children){
                    q.push(child);
                }
            }
            levels.push_back(level);
        }
        return levels;
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    vector<vector<Node*>> layers;
    void dfs(Node* root, int layer){
        if(!root) return;
        
        while(layer >= layers.size()) layers.push_back({});
        if(!layers[layer].empty()) layers[layer].back()->next = root;
        layers[layer].push_back(root);
        
        dfs(root->left,layer+1);
        dfs(root->right,layer+1);
        
    }
public:
    Node* connect(Node* root) {
        if(!root) return root;
        dfs(root,0);
        /**
        for(auto layer: layers){
            for(int i = 0; i < layer.size()-1; i++){
                layer[i]->next = layer[i+1];
            }
            //layer.back()->next = nullptr;
        }
        **/
        return root;
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
    pair<Node*,Node*> traverse(Node* root){
        if(!root) return {nullptr,nullptr};
        if(!root->left && !root->right) return {root,root};
        auto [lhead,ltail] = traverse(root->left);
        auto [rhead,rtail] = traverse(root->right);
        if(ltail){
            ltail->right = root;
            root->left = ltail;
        }
        if(rhead){
            root->right = rhead;
            rhead->left = root;
        }
        if(lhead && rtail) return {lhead,rtail};
        if(lhead) return {lhead,root};
        else return {root,rtail};
    }
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return nullptr;
        auto [head,tail] = traverse(root);
        tail->right = head;
        head->left = tail;
        return head;
    }
};
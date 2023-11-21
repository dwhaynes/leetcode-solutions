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
    Node *first=nullptr, *last=nullptr;
    void traverse(Node* node){
        if(node){
            traverse(node->left);
            if(last){
                last->right = node;
                node->left = last;
            }else{
                first = node;
            }
            last = node;
            traverse(node->right);
        }
    }
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return nullptr;
        traverse(root);
        first->left = last;
        last->right = first;
        return first;
    }
};
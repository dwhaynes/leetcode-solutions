/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
    int len(Node* node){
        int sz = 0;
        while(node){
            node = node->parent;
            sz++;
        }
        return sz;
    }
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        int lp = len(p);
        int lq = len(q);
        if(lq > lp){
            swap(p,q);
            swap(lp,lq);
        }
        for(int i = 0; i < lp-lq; i++) p = p->parent;
        while(p != q){
            p = p->parent;
            q = q->parent;
        }
        return p;
    }
};
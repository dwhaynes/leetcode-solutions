/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    map<Node*,Node*> map;
    Node* clone(Node* head){
        if(!head) return nullptr;
        if(map.find(head) != map.end()) return map[head];
        Node* temp = new Node(head->val);
        map[head] = temp;
        for(auto n: head->neighbors){
            temp->neighbors.push_back(clone(n));
        }
        return temp;
    }
public:
    Node* cloneGraph(Node* node) {
        return clone(node);
    }
};
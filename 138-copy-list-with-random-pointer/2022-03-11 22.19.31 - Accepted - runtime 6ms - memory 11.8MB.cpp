/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    map<Node*,Node*> map;
    Node* dfs(Node* head){
        if(!head) return nullptr;
        if(map.find(head) != map.end()) return map[head];
        Node* temp = new Node(head->val);
        map[head]=temp;
        temp->next = dfs(head->next);
        temp->random = dfs(head->random);
        
        return temp;
    }
public:
    Node* copyRandomList(Node* head) {
        return dfs(head);
    }
};
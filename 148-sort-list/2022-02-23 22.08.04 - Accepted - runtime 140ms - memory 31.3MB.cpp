/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    struct comp{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
    priority_queue<ListNode*,vector<ListNode*>,comp> pq;
public:
    ListNode* sortList(ListNode* head) {
        if (!head) return nullptr;
        ListNode* temp;
        while(head){
            temp = head->next;
            head->next = nullptr;
            pq.push(head);
            head = temp;
        }
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while(!pq.empty()){
            curr->next = pq.top();
            pq.pop();
            curr = curr->next;
        }
        return dummy->next;
        
    }
};
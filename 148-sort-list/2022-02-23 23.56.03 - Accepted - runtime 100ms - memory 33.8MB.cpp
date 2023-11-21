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
priority_queue<int,vector<int>,greater<int>> pq;
public:
    ListNode* sortList(ListNode* head) {
        if (!head) return nullptr;
        while(head){
            pq.push(head->val);
            head = head->next;
        }
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while(!pq.empty()){
            curr->next = new ListNode(pq.top());
            pq.pop();
            curr = curr->next;
        }
        return dummy->next;
        
    }
};
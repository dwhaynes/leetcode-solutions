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
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;
        ListNode *lt, *ge;
        lt = new ListNode();
        ge = new ListNode();
        ListNode *ltail = lt;
        ListNode *gtail = ge;
        for(ListNode* curr = head; curr != nullptr; curr = curr->next){
            if (curr->val < x){
                ltail->next = curr;
                ltail = ltail->next;
            }else{
                gtail->next = curr;
                gtail = gtail->next;
            }
        }
        ltail->next = ge->next;
        gtail->next = nullptr;
        return lt->next;
    }
};
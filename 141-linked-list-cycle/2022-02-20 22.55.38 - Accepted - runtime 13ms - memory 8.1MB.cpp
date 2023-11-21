/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        if(!head->next) return false;
        ListNode *fast, *slow;
        slow = head;
        fast = head->next;
        while(fast && fast->next && fast->next->next && fast!=slow){
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast == slow) return true;
        return false;
    }
};
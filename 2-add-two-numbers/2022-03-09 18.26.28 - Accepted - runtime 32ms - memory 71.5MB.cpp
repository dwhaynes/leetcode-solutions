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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* res = new ListNode();
        ListNode* current = res;
        while(l1 && l2){
            int digit = l1->val + l2->val + carry;
            carry = digit/10;
            digit%=10;
            current->next = new ListNode(digit);
            current = current->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int digit = l1->val + carry;
            carry = digit/10;
            digit%=10;
            current->next = new ListNode(digit);
            current = current->next;
            l1 = l1->next;
        }
        while(l2){
            int digit = l2->val + carry;
            carry = digit/10;
            digit%=10;
            current->next = new ListNode(digit);
            current = current->next;
            l2 = l2->next;
        }
        if(carry){
            current->next = new ListNode(1);
        }
        return res->next;
    }
};
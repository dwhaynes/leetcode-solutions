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
    int carry = 0;
    ListNode *ans, *head;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ans = new ListNode();
        head = ans;
        while(l1 && l2){
            int num = carry + l1->val + l2->val;
            carry = num / 10;
            num %= 10;
            head->next = new ListNode(num);
            l1 = l1->next;
            l2 = l2->next;
            head = head->next;
        }
        while(l1){
            int num = carry + l1->val;
            carry = num / 10;
            num %= 10;
            head->next = new ListNode(num);
            l1 = l1->next;
            head = head->next;

        }
        while(l2){
            int num = carry + l2->val;
            carry = num / 10;
            num %= 10;
            head->next = new ListNode(num);
            l2 = l2->next;
            head = head->next;
        }
        if(carry){
            head->next = new ListNode(1);
        }
        return ans->next;
    }
};
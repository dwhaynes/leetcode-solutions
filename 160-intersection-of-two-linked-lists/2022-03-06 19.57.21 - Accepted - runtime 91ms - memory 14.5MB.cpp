/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int len(ListNode* curr){
        if(!curr) return 0;
        int sz = 1;
        while(curr->next){
            curr = curr->next;
            sz++;
        }
        return sz;
        
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = len(headA);
        int lenB = len(headB);
        if(lenB > lenA){
            swap(headA,headB);
            swap(lenA,lenB);
        }
        while(lenA > lenB){
            headA = headA->next;
            lenA--;
        }
        while(headA && headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
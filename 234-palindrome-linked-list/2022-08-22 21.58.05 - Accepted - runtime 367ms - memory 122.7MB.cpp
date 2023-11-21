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
    ListNode *front;
    bool check(ListNode* curr){
        if(curr){
            if(!check(curr->next)) return false;
            if(curr->val != front->val) return false;
            front = front->next;
        }
        return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        front = head;
        return check(head);
    }
};
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
    ListNode* dummy;
public:
    bool helper(ListNode* curr){
        if(curr){
            if(!helper(curr->next)) return false;
            if(curr->val != dummy->val) return false;
            dummy = dummy->next;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        dummy = head;
        return helper(dummy);
    }
};
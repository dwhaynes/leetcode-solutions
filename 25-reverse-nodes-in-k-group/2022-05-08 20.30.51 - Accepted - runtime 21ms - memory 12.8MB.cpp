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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return nullptr;
        ListNode* curr = head;
        stack<ListNode*> stack;
        int i;
        for(i = 0; i < k && curr != nullptr; i++, curr = curr->next){
            stack.push(curr);
        }
        if(curr == nullptr && i != k) return head;
        ListNode* tail = curr;
        head = stack.top();
        stack.pop();
        curr = head;
        while(!stack.empty()){
            curr->next = stack.top();
            curr = curr->next;
            stack.pop();
        }
        curr->next = reverseKGroup(tail,k);
        return head;
    }
};
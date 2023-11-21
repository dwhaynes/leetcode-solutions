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
    ListNode* middle;
    int max_depth = INT_MIN;
    void search(ListNode* head, int depth){
        if(!head){
            max_depth = depth;
            return;
        }
        search(head->next,depth+1);
        if(max_depth/2 == depth) middle = head;
    }
public:
    ListNode* middleNode(ListNode* head) {
        if(!head) return nullptr;
        search(head,0);
        return middle;
    }
};
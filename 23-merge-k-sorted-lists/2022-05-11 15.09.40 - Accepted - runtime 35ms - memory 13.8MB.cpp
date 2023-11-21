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
    ListNode* merge2(ListNode* a, ListNode* b){
        if(!a) return b;
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while (a && b){
            if(a->val < b->val){
                curr->next = a;
                a = a->next;
            }else{
                curr->next = b;
                b = b->next;
            }
            curr = curr->next;
        }
        while(a){
            curr->next = a;
            a = a->next;
            curr = curr->next;
        }
        while(b){
            curr->next = b;
            b = b->next;
            curr = curr->next;
        }
        return dummy->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        deque<ListNode*> dq(lists.begin(),lists.end());
        while(dq.size() > 1){
            ListNode *a, *b;
            a = dq.front();
            dq.pop_front();
            b = dq.front();
            dq.pop_front();
            dq.push_back(merge2(a,b));
        }
        return dq.front();
    }
};
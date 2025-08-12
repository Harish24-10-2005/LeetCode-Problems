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
    ListNode *detectCycle(ListNode *head) {
        if(!head) return nullptr;
        ListNode* s = head;
        ListNode* f = head->next;
        int fl = 0;
        while(f!= nullptr && f->next!=nullptr)
        {
            if(f == s)
            {
                fl = 1;
                break;
            }
            s = s->next;
            f = f->next->next;
        }
        if(!fl) return nullptr;
        f = head;
        while(s!=f)
        {
            s = s->next;
            f = f->next->next;
        }
        return s;
    }
};
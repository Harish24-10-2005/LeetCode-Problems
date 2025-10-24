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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        ListNode* d = new ListNode(0);
        d->next = head;
        ListNode* s = d;
        ListNode* f = d;
        for(int i=0;i<=n;i++)
        {
            f = f->next;
        }
        while(f)
        {
            f = f->next;
            s = s->next;
        }
        ListNode* temp= s->next;
        if(s->next)s->next = s->next->next;
        else s->next = nullptr;
        delete temp;
        return d->next;
    }
};
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
private:
    ListNode* rev(ListNode* st,ListNode* end)
    {
        ListNode* pre = nullptr;
        while(st != end)
        {
            ListNode* next = st->next;
            st->next = pre;
            pre = st;
            st = next;
        }
        return pre;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;

        ListNode* temp = head;
        for(int i=0;i<k;i++)
        {
            if(!temp) return head;
            temp =  temp->next;
        }

        ListNode* newhead = rev(head,temp);

        head->next = reverseKGroup(temp,k);

        return newhead;
    }
};
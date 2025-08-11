/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int lenn(ListNode* temp)
    {
        int l = 0;
        while(temp)
        {
            l++;
            temp = temp->next;
        }
        return l;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        int l1 = lenn(temp1);
        int l2 = lenn(temp2);
        if(l1 > l2)
        {
            temp1 = headA;
            temp2 = headB;
        }
        else
        {
            temp1 = headB;
            temp2 = headA;
        }
        int diff = max(l1,l2) - min(l1,l2);
        for(int i=0;i<diff;i++)
        {
            temp1 = temp1->next;
        }
        while(temp1 != temp2)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return temp1;
    }
};
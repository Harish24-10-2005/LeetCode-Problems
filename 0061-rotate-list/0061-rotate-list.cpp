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
    ListNode* rotateRight(ListNode* head, int k) {
        int l = 0;
        ListNode* temp = head;
        ListNode* last;
        while(temp!= nullptr)
        {
            l++;
            if(temp -> next == nullptr) last= temp;
            temp = temp->next;
        }
        if(l<= 1) return head;
        // l++;
        last->next = head;
        int need = k%l;
        int g = l - need;
        cout<<g<<endl;
        temp = head;
        while(g>1)
        {
            temp = temp->next;
            g--;
        }
        head = temp->next;
        temp->next = nullptr;
        return head;
    }
};
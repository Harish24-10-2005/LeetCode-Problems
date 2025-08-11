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
    ListNode* rev(ListNode* l)
    {
        ListNode* cur = l;
        ListNode* pre = nullptr;
        while(cur!=nullptr)
        {
            ListNode* n = cur->next;
            cur->next = pre;
            pre = cur;
            cur = n;
        }
        return pre;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        ListNode*f = rev(l1);
        ListNode*s = rev(l2);
        int carry = 0;

        // while(s!=nullptr)
        // {
        //     cout<<s->val<<endl;
        //     s = s->next;
        // }
        while(f && s)
        {
            int ans = f->val + s->val + carry;
            // cout<<ans<<endl;
            carry = 0;
            string st = to_string(ans);
            // cout<<st<<endl;
            if(st.size() == 2)
            {
                carry = st[0]-'0';
                ans = st[1] -'0';
            } 
            ListNode* a = new ListNode(ans);
            f = f->next;
            s = s->next;
            temp->next = a;
            temp =  temp->next;
        }
        while(f)
        {
            int ans = f->val + carry;
            carry = 0;
            string st = to_string(ans);
            // cout<<st<<endl;
            if(st.size() == 2)
            {
                carry = st[0]-'0';
                ans = st[1] -'0';
            } 
            ListNode* a = new ListNode(ans);
            f = f->next;
            temp->next = a;
            temp =  temp->next;
        }
        while(s)
        {
            int ans = s->val + carry;
            carry = 0;
            string st = to_string(ans);
            // cout<<st<<endl;
            if(st.size() == 2)
            {
                carry = st[0]-'0';
                ans = st[1] -'0';
            } 
            ListNode* a = new ListNode(ans);
            s = s->next;
            temp->next = a;
            temp =  temp->next;
        }
        if(carry!=0)
        {
            ListNode* a = new ListNode(carry);
            temp->next = a;
        }
        return head->next;
    }
};
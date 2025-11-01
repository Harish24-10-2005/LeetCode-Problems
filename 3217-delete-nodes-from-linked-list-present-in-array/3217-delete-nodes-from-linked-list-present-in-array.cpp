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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st(nums.begin(),nums.end());

        while(head && st.find(head->val) != st.end())
        {
            head = head->next;
        }
        if(!head || !head->next) return head;

        ListNode* temp = head;
        while(temp && temp->next)
        {
            int data = temp->next->val;
            // cout<<"data"<<endl;
            ListNode* temp2 = temp->next;
            while(temp2 && st.find(temp2->val)!=st.end())
            {
                // cout<<temp2->val<<endl;
                temp2 = temp2->next;
            }   
            temp->next = temp2;
            temp = temp->next;
        }
        return head;
    }
};
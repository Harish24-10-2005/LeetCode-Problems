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
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; 
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*>,compare>pq;
        for (auto node : lists) {
            ListNode* temp = node;
            while (temp) {
                pq.push(temp);
                temp = temp->next;
            }
        }
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        while(!pq.empty())
        {
            auto a = pq.top();
            a->next = nullptr;
            pq.pop();
            temp->next = a;
            temp = temp->next;
            // cout<<a->val<<" ";
        }
        // ListNode* a = new ListNode(0);
        return head->next;
    }
};
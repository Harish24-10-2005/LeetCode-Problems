# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        stack = []
        for i in lists:
            while i:
                stack.append(i.val)
                i = i.next
        stack.sort()
        dummy = ListNode()
        cur = dummy
        for k in stack:
            cur.next = ListNode(k)
            cur = cur.next
        return dummy.next
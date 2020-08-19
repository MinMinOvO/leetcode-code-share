# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        if not head:
            return None
        if not head.next:
            return head
        n = head.next
        t = head
        while n:
            if n.val < t.val:
                i = head
                while i.val <= n.val:
                    j = i
                    i = i.next
                t.next = n.next
                n.next = i
                if i is head:
                    head = n
                else:
                    j.next = n
                n = t
            t = n
            n = n.next
        return head
                
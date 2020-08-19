# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head
        a, b = head, head.next
        head_b = b
        c = b.next
        idx = 3
        while c is not None:
            if idx & 1:
                a.next = c
                a = c
            else:
                b.next = c
                b = c
            idx += 1
            c = c.next
        a.next = head_b
        b.next = None
        return head
        
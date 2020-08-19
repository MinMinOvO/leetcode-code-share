# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
from copy import deepcopy
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        linkedlist = deepcopy(l1)
        l1 = linkedlist
        carry = 0
        while l1 is not None and l2 is not None:
            result = l1.val + l2.val + carry
            carry = int(result / 10)
            l1.val = result - carry * 10
            l3 = l1
            l1 = l1.next
            l2 = l2.next
        if l2 != None:
            l3.next = deepcopy(l2)
            l1 = l3.next
        while carry != 0 and l1 is not None:
            result = l1.val + carry
            carry = int(result / 10)
            l1.val = result - carry * 10
            l3 = l1
            l1 = l1.next
        if carry != 0:
            l3.next = ListNode(carry)
        return linkedlist
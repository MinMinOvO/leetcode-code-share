"""
# Definition for a Node.
class Node:
    def __init__(self, val, next, random):
        self.val = val
        self.next = next
        self.random = random
"""
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if not head:
            return None
        copy_head = Node(val=head.val, next=None, random=None)
        my_dict = {}
        n1 = head
        n2 = copy_head
        while True:
            my_dict[n1] = n2
            n1 = n1.next
            if not n1:
                break
            n2.next = Node(val=n1.val, next=None, random=None)
            n2 = n2.next
        n1 = head
        n2 = copy_head
        while n1:
            if n1.random:
                n2.random = my_dict[n1.random]
            n1 = n1.next
            n2 = n2.next
        return copy_head
        
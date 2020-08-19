# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        N = len(lists)
        i = 0
        while i < N:
            if not lists[i]:
                del lists[i]
                i -= 1
                N -= 1
            i += 1
        if not lists:
            return None
        head = min(lists, key=lambda listnode: listnode.val)
        idx_head = lists.index(head)
        if head.next:
            lists[idx_head] = head.next
        else:
            del lists[idx_head]
        n = head
        while lists:
            m = min(lists, key=lambda listnode: listnode.val)
            idx_m = lists.index(m)
            if m.next:
                lists[idx_m] = m.next
            else:
                del lists[idx_m]
            n.next = m
            n = m
        return head
    
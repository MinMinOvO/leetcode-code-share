# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def splitListToParts(self, root: ListNode, k: int) -> List[ListNode]:
        if root is None:
            return [None for _ in range(k)]
        nodes = []
        length = 0
        while root is not None:
            length += 1
            if length % 100 == 1:
                nodes.append(root)
            root = root.next
        part_length = length // k
        num_long = length % k

        result = [nodes[0]]
        num_rep = 1
        idx_target = -1
        idx_cur = 0
        node_cur = nodes[0]
        while num_rep < k:
            idx_target += (part_length + 1) if num_rep <= num_long else part_length
            if idx_target % 100 < idx_target - idx_cur:
                idx = idx_target // 100
                node_cur = nodes[idx]
                idx_cur = idx * 100
            while idx_cur < idx_target:
                node_cur = node_cur.next
                idx_cur += 1    
            result.append(node_cur.next)
            next_ = node_cur.next
            node_cur.next = None
            node_cur = next_
            idx_cur += 1
            num_rep += 1
            if node_cur is None:
                while num_rep < k:
                    result.append(None)
                    num_rep += 1
                break
        return result
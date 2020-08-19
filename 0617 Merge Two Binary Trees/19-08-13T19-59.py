# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque

class Solution:
    def mergeTrees(self, t1: TreeNode, t2: TreeNode) -> TreeNode:
        if t1 is None:
            return t2
        que1 = deque([(t1, None, True)])
        que2 = deque([t2])
        while que1:
            (node1, f1, isleft), node2 = que1.popleft(), que2.popleft()
            if node2 is not None:
                if node1 is not None:
                    node1.val += node2.val
                    que1.append((node1.left, node1, True))
                    que1.append((node1.right, node1, False))
                    que2.append(node2.left)
                    que2.append(node2.right)
                else:
                    if isleft:
                        f1.left = node2
                    else:
                        f1.right = node2
        return t1
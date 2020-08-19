# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque


class Solution:
    def isCompleteTree(self, root: TreeNode) -> bool:
        que = deque([(root, 1)])
        idx_expc = 1
        while len(que) > 0:
            node, idx = que.popleft()
            if idx != idx_expc:
                return False
            if node.left is not None:
                que.append((node.left, idx << 1))
            if node.right is not None:
                que.append((node.right, (idx << 1) | 1))
            idx_expc += 1
        return True
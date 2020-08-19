# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque
class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:
        que = deque([root])
        while len(que) > 0:
            node = que.popleft()
            if node.right is not None:
                que.append(node.right)
            if node.left is not None:
                que.append(node.left)
        return node.val
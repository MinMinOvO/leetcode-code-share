# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque


class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        if root is None:
            return 0
        que = deque([(root, 0, 0)])
        width_max = 1
        l_cur = 0
        w_pre = -1
        left = 0
        while len(que) > 0:
            node, l, w = que.popleft()
            if l > l_cur:
                l_cur = l
                width_max = max(width_max, w_pre - left + 1)
                left = w
            if node.left is not None:
                que.append((node.left, l+1, (w<<1)))
            if node.right is not None:
                que.append((node.right, l+1, (w<<1)|1))
            w_pre = w
        width_max = max(width_max, w_pre - left + 1)
        return width_max
"""
# Definition for a Node.
class Node:
    def __init__(self, val, left, right, next):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
from collections import deque
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root is None:
            return root
        arr = deque([root])
        while arr:
            n = len(arr)
            for i in range(n):
                node = arr.popleft()
                if node.left is not None:
                    arr.append(node.left)
                if node.right is not None:
                    arr.append(node.right)
                if i == n-1:
                    node.next = None
                else:
                    node.next = arr[0]
        return root
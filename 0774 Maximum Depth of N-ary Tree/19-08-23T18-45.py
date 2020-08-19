"""
# Definition for a Node.
class Node:
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution:
    def maxDepth(self, root: 'Node') -> int:
        def getDepth(root):
            if not root.children:
                return 1
            return max([getDepth(root=node) for node in root.children]) + 1
        if not root:
            return 0
        return getDepth(root)
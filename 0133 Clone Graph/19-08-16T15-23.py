"""
# Definition for a Node.
class Node:
    def __init__(self, val, neighbors):
        self.val = val
        self.neighbors = neighbors
"""
from copy import deepcopy
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        return deepcopy(node)
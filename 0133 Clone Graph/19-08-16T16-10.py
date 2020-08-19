"""
# Definition for a Node.
class Node:
    def __init__(self, val, neighbors):
        self.val = val
        self.neighbors = neighbors
"""
from collections import deque
from copy import copy

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if node is None:
            return None
        node_copy = Node(val=copy(node.val), neighbors=[])
        node_dict = {node: node_copy}
        que = deque([node])
        while que:
            n = que.popleft()
            for neighbor in n.neighbors:
                if neighbor in node_dict:
                    node_dict[n].neighbors.append(node_dict[neighbor])
                else:
                    neighbor_copy = Node(val=copy(neighbor.val), neighbors=[])
                    node_dict[n].neighbors.append(neighbor_copy)
                    node_dict[neighbor] = neighbor_copy
                    que.append(neighbor)
        return node_copy
                    
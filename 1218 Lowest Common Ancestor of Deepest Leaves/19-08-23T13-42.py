# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque

class Solution:
    def lcaDeepestLeaves(self, root: TreeNode) -> TreeNode:
        def getHeight(height_dict, node):
            if node is None:
                return 0
            else:
                return height_dict[node]
        if root is None:
            return None
        height_dict = {}
        node_que = deque([root])
        vis_que = deque([False])
        while node_que:
            if vis_que[-1]:
                node = node_que.pop()
                vis_que.pop()
                height_dict[node] = max(getHeight(height_dict, node.left), getHeight(height_dict, node.right)) + 1
            else:
                vis_que[-1] = True
                node = node_que[-1]
                if node.left is not None:
                    node_que.append(node.left)
                    vis_que.append(False)
                if node.right is not None:
                    node_que.append(node.right)
                    vis_que.append(False)
        node = root
        while True:
            height1, height2 = getHeight(height_dict, node.left), getHeight(height_dict, node.right)
            if height1 == height2:
                return node
            if height1 > height2:
                node = node.left
            else:
                node = node.right
            
        
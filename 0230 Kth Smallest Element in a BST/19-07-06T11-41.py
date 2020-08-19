# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        s1 = [root]
        s2 = [False]
        cnt = 0
        while len(s1) > 0:
            if s2[-1]:
                node = s1.pop()
                s2.pop()
                if node.right is not None:
                    s1.append(node.right)
                    s2.append(False)
                cnt += 1
                if cnt == k:
                    return node.val
            else:
                s2[-1] = True
                if s1[-1].left is not None:
                    s1.append(s1[-1].left)
                    s2.append(False)
        raise Exception("k is not valid")
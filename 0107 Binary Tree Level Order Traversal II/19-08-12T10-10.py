# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []
        ans = [[root]]
        cont = True
        while cont:
            cont = False
            for val in ans[-1]:
                if val.left is not None:
                    if not cont:
                        ans.append([val.left])
                        cont = True
                    else:
                        ans[-1].append(val.left)
                if val.right is not None:
                    if not cont:
                        ans.append([val.right])
                        cont = True
                    else:
                        ans[-1].append(val.right)
        ans.reverse()
        ans = [[node.val for node in arr] for arr in ans]
        return ans
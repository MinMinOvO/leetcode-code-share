# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    
    def maxLevelSum(self, root: TreeNode) -> int:
        a, b = [root], []
        vals_perlevel = []
        while len(a) > 0:
            vals_perlevel.append(sum(o.val for o in a))
            for o in a:
                if o.left:
                    b.append(o.left)
                if o.right:
                    b.append(o.right)
            a, b = b, a
            b.clear()
        return vals_perlevel.index(max(vals_perlevel))+1
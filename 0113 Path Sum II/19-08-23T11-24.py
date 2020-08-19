# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        def my_pathSum(root: TreeNode, sum: int):
            next_sum = sum - root.val
            if root.left is None and root.right is None:
                return [[root.val]] if next_sum == 0 else []
            else:
                path = []
                if root.left is not None:
                    path += my_pathSum(root=root.left, sum=next_sum)
                if root.right is not None:
                    path += my_pathSum(root=root.right, sum=next_sum)
                for arr in path:
                    arr.append(root.val)
                return path
        ans = my_pathSum(root=root, sum=sum) if root is not None else []
        for arr in ans:
            arr.reverse()
        return ans
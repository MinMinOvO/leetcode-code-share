# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    
    def delNodes(self, root: TreeNode, to_delete: List[int]) -> List[TreeNode]:
        roots = [root]
        for t in to_delete:
            for r in roots:
                
                def findTreeNodeInRoot(root, parent, to_delete):
                    if root.val == to_delete:
                        return root, parent
                    node, parent = None, None
                    if root.left:
                        node, parent = findTreeNodeInRoot(root.left, root, to_delete)
                    if not node and root.right:
                        node, parent = findTreeNodeInRoot(root.right, root, to_delete)
                    return node, parent
    
                node, parent = findTreeNodeInRoot(r, None, t)
                if node:
                    if parent:
                        if node == parent.left:
                            parent.left = None
                        elif node == parent.right:
                            parent.right = None
                        else:
                            print("find parent of node error")
                    else:
                        del roots[roots.index(node)]
                    if node.left:
                        roots.append(node.left)
                    if node.right:
                        roots.append(node.right)
                    break
                    
            else:
                print("not exsit value")
        return roots
            
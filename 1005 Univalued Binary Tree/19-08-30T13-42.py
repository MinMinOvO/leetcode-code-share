class Solution:
    def isUnivalTree(self, root: TreeNode) -> bool:
        def treenode_postorder_iter(self):
            if self.left:
                for treenode in self.left:
                    yield treenode
            if self.right:
                for treenode in self.right:
                    yield treenode
            yield self
        setattr(TreeNode, '__iter__', treenode_postorder_iter)
        val = root.val
        return all((treenode.val==val for treenode in root))

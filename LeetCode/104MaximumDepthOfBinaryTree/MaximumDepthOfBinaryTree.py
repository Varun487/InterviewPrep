class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        # Inorder traversal -> Time:O(n), Space:O(1)
        if root == None:
            return 0
        else:
            return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))

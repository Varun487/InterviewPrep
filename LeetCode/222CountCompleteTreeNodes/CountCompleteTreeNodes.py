class Solution:
    def leftHeight(self, root: Optional[TreeNode]) -> int:
        if root:
            return 1 + self.leftHeight(root.left)
        return 0
    def rightHeight(self, root: Optional[TreeNode]) -> int:
        if root:
            return 1 + self.rightHeight(root.right)
        return 0
    def countNodes(self, root: Optional[TreeNode]) -> int:
        # Binary search on leaves -> Time:O(logn*logn), Space:O(h)
        left_depth = self.leftHeight(root)
        right_depth = self.rightHeight(root)
        if left_depth == right_depth:
            return 2**left_depth - 1
        return 1 + self.countNodes(root.left) + self.countNodes(root.right)

        # DFS -> Time:O(n), Space:O(h)
        # if root:
        #     return 1 + self.countNodes(root.left) + self.countNodes(root.right)
        # return 0

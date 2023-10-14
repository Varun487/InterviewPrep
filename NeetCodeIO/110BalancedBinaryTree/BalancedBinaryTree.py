class Solution:
    def getHeight(self, root):
        if not root:
            return (0, True)
        leftHeight, leftBool = self.getHeight(root.left)
        rightHeight, rightBool = self.getHeight(root.right)
        return (1 + max(leftHeight, rightHeight), abs(leftHeight - rightHeight) <= 1 and leftBool and rightBool)

    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        # DFS -> Time:O(n), Space:O(h)
        return self.getHeight(root)[1]

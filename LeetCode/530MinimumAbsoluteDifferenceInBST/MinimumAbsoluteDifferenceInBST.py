class Solution:
    min_diff = float("inf")
    prev = None

    def dfs(self, root):
        if not root:
            return
        self.dfs(root.left)
        if self.prev:
            self.min_diff = min(self.min_diff, root.val - self.prev.val)
        self.prev = root
        self.dfs(root.right)

    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        # Inorder -> Time:O(n), Space:O(h)
        self.dfs(root)
        return self.min_diff

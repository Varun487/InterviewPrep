class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        # DFS -> Time:O(n), Space:O(n)
        ans = [0]
        def dfs(root):
            if not root:
                return -1
            left = dfs(root.left)
            right = dfs(root.right)
            ans[0] = max(ans[0], 2 + left + right)
            return 1 + max(left, right)
        dfs(root)
        return ans[0]

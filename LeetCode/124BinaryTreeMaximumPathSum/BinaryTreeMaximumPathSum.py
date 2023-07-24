class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        # DFS -> Time:O(n), Space:O(h)
        ans = [root.val]
        def dfs(root):
            if not root:
                return 0
            leftMax = max(dfs(root.left), 0)
            rightMax = max(dfs(root.right), 0)
            ans[0] = max(ans[0], root.val + leftMax + rightMax)
            return root.val + max(leftMax, rightMax)
        dfs(root)
        return ans[0]

class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        # DFS -> Time:O(n), Space:O(h)
        def dfs(left, right):
            if not left and not right:
                return True
            elif not left or not right:
                return False
            return left.val == right.val and dfs(left.left, right.right) and dfs(left.right, right.left)
        if root == None:
            return True
        return dfs(root.left, root.right)

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        # DFS -> Time:O(n), Space:O(h)
        def valid(root, left, right):
            if not root:
                return True
            if left < root.val < right:
                return valid(root.left, left, root.val) and valid(root.right, root.val, right)
            return False
        return valid(root, float("-inf"), float("inf"))

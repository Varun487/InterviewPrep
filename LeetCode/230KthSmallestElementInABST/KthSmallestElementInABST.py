class Solution:
    index = 1
    ans = -1
    def inorder(self, root, k):
        if not root:
            return
        self.inorder(root.left, k)
        if k == self.index:
            self.ans = root.val
        self.index += 1
        self.inorder(root.right, k)

    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        # DFS -> Time:O(n), Space:O(h)
        self.inorder(root, k)
        return self.ans

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        # Inorder traversal -> Time:O(n), Space:O(1)
        if p == None and q == None:
            return True
        elif p != None and q != None:
            if p.val == q.val:
                return True and self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
            return False
        return False

class BSTIterator:

    def __init__(self, root: Optional[TreeNode]):
        # Iterative DFS -> Time:O(n), Space:O(h)
        self.stack = []
        while root:
            self.stack.append(root)
            root = root.left

    def next(self) -> int:
        res = self.stack.pop()
        curr = res.right
        while curr:
            self.stack.append(curr)
            curr = curr.left
        return res.val

    def hasNext(self) -> bool:
        return self.stack != []

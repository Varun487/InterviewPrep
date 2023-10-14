class Solution:
    ans = 0
    def countGoodNodes(self, node, parent):
        if not node:
            return 
        if not parent or node.val >= parent.val:
            self.ans += 1
            parent = node
        self.countGoodNodes(node.left, parent)
        self.countGoodNodes(node.right, parent)

    def goodNodes(self, root: TreeNode) -> int:
        # DFS -> Time:O(n), Space:O(n)
        self.countGoodNodes(root, None)
        return self.ans

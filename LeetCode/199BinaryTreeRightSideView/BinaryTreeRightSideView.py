class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        # BFS -> Time:O(n), Space:O(2^h)
        ans = []
        if not root:
            return ans
        q = []
        q.append(root)
        while q:
            size = len(q)
            ans.append(q[-1].val)
            for i in range(size):
                node = q.pop(0)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
        return ans

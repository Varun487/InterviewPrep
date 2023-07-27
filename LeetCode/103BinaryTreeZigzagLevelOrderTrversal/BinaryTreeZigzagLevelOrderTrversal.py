class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        # BFS -> Time:O(n), Space:O(2^h)
        ans = []
        if not root:
            return ans
        q = []
        q.append(root)
        zigzag = 0
        while q:
            level = []
            size = len(q)
            for i in range(size):
                front = q.pop(0)
                if front.left:
                    q.append(front.left)
                if front.right:
                    q.append(front.right)
                level.append(front.val)
            if zigzag:
                ans.append(reversed(level))
                zigzag = 0
            else:
                ans.append(level)
                zigzag = 1
        return ans

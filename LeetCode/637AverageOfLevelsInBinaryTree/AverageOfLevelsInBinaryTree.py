class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        # BFS -> Time:O(n), Space:O(2^h)
        q = []
        q.append(root)
        ans = []
        while q:
            size = len(q)
            level_sum = 0
            for i in range(size):
                node = q.pop(0)
                level_sum += node.val
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            ans.append(level_sum/size)
        return ans

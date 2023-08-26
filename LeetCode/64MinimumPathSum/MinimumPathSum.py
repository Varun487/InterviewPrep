class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        # 1D DP -> Time:O(n*m), Space:O(m)
        rows, cols = len(grid), len(grid[0])
        ans = [float("inf")] * (cols+1)
        ans[cols-1] = 0
        for i in range(rows-1, -1, -1):
            for j in range(cols-1, -1, -1):
                ans[j] = grid[i][j] + min(ans[j],ans[j+1])
        return ans[0]

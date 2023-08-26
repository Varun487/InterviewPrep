class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        # 1D DP -> Time:O(n*m), Space:O(m)
        rows, cols = len(obstacleGrid), len(obstacleGrid[0])
        dp = [0] * cols
        dp[cols-1] = 1
        for i in range(rows-1, -1, -1):
            for j in range(cols-1, -1, -1):
                if obstacleGrid[i][j]:
                    dp[j] = 0
                elif j+1 < cols:
                    dp[j] = dp[j] + dp[j+1]
        return dp[0]

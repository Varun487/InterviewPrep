class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        # 2D DP -> Time:O(k*n), Space:O(k*n)
        dp = [[0]*len(prices) for i in range(k+1)]
        for i in range(1, k+1):
            max_diff = -prices[0]
            for j in range(1, len(prices)):
                dp[i][j] = max(dp[i][j-1], prices[j] + max_diff)
                max_diff = max(max_diff, dp[i-1][j] - prices[j])
        return dp[k][len(prices)-1]

        # # 2D DP -> Time:O(k*n^2), Space:O(k*n) -> Time Limit Exceeded
        # dp = [[0]*len(prices) for i in range(k+1)]
        # for i in range(1, k+1):
        #     for j in range(1, len(prices)):
        #         dp[i][j] = max(dp[i][j-1], prices[j]-prices[0]+dp[i-1][0])
        #         for m in range(1, j):
        #             dp[i][j] = max(dp[i][j], prices[j]-prices[m]+dp[i-1][m])
        # return dp[k][len(prices)-1]

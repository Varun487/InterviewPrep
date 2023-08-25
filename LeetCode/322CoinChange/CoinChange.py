class Solution:
    min_coins = float("inf")
    def coinChange(self, coins: List[int], amount: int) -> int:
        # 1D Dynamic programming -> Time:O(n*amount), Space:O(amount) where n=len(coins)
        dp = [amount + 1] * (amount + 1)
        dp[0] = 0
        for i in range(1, amount + 1):
            for j in range(len(coins)):
                if i - coins[j] >= 0:
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]])
        return -1 if dp[amount] == amount + 1 else dp[amount]

        # # DFS -> Time:O(n^amount), Space:O(amount) where n=len(coins) -> Time limit exceeded
        # def dfs(current_amount, index, depth):
        #     if current_amount >  amount:
        #         return
        #     if current_amount == amount:
        #         if depth < self.min_coins:
        #             self.min_coins = depth
        #         return
        #     current_amount += coins[index]
        #     for i in range(len(coins)):
        #         dfs(current_amount, i, depth+1)
        # for i in range(len(coins)):
        #     dfs(0, i, 0)
        # return -1 if self.min_coins == float("inf") else self.min_coins

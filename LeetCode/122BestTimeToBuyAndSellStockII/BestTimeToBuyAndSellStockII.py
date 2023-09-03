class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # Time: O(n), Space: O(1)
        profit = 0
        for i in range(1, len(prices)):
            diff = prices[i] - prices[i-1]
            if diff > 0:
                profit += diff
        return profit

        # # Two pointers -> Time: O(n), Space: O(1)
        # l, r = 0, 1
        # max_profit = 0
        # while r < len(prices):
        #     profit = prices[r] - prices[l]
        #     max_profit += max(0, profit)
        #     l += 1
        #     r += 1
        # return max_profit

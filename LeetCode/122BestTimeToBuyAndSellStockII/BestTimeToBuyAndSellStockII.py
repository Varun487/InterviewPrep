class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # Two pointers -> Time: O(n), Space: O(1)
        l, r = 0, 1
        max_profit = 0
        while r < len(prices):
            profit = prices[r] - prices[l]
            max_profit += max(0, profit)
            l += 1
            r += 1
        return max_profit

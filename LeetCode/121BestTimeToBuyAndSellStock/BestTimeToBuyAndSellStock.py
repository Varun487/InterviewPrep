class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # Time:O(n), Space:O(1)
        min_price = prices[0]
        max_profit = 0
        for price in prices:
            if price < min_price:
                min_price = price
            else:
                max_profit = max(max_profit, price-min_price)
        return max_profit

        # Two pointers -> Time: O(n), Space: O(1)
        l, r = 0, 1
        max_profit = 0
        while r < len(prices):
            if prices[l] > prices[r]:
                l = r
            else:
                profit = prices[r] - prices[l]
                max_profit = max(max_profit, profit)
            r += 1
        return max_profit

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # Bidirectional DP -> Time:O(n), Space:O(n)
        left = [0]*len(prices)
        right = [0]*len(prices)
        min_price = prices[0]
        for i in range(1, len(prices)):
            min_price = min(prices[i], min_price)
            left[i] = max(left[i-1], prices[i] - min_price)
        max_price = prices[-1]
        for i in range(len(prices)-2, -1, -1):
            max_price = max(prices[i], max_price)
            right[i] = max(right[i+1], max_price - prices[i])
        max_profit = 0
        for i in range(len(prices)):
            max_profit = max(max_profit, left[i]+right[i])
        return max_profit

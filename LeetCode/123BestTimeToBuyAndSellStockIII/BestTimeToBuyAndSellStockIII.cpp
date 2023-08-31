class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Bidirectional DP -> Time:O(n), Space:O(n)
        vector<int> left(prices.size(), 0), right(prices.size(), 0);
        int n = prices.size(), minPrice = prices[0], maxPrice = prices[n-1], maxProfit = 0;
        for (int i = 1; i < n; i++) {
            minPrice = min(minPrice, prices[i]);
            left[i] = max(left[i-1], prices[i] - minPrice);
        }
        for (int i = n-2; i > -1; i--) {
            maxPrice = max(maxPrice, prices[i]);
            right[i] = max(right[i+1], maxPrice - prices[i]);
        }
        for (int i = 0; i < n; i++) {
            maxProfit = max(maxProfit, left[i]+right[i]);
        }
        return maxProfit;
    }
};

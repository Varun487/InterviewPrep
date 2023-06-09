class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Two pointers -> Time: O(n), Space: O(1)
        int profit, l = 0, r = 1, max_profit = 0;
        while (r < prices.size()) {
            if (prices[l] > prices[r]) {
                l = r;
            }
            else {
                profit = prices[r] - prices[l];
                if (profit > max_profit) {
                    max_profit = profit;
                }
            }
            r++;
        }
        return max_profit;
    }
};
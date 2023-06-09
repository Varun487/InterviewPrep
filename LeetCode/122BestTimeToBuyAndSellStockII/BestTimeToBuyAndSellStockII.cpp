class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Two pointers -> Time: O(n), Space: O(1)
        int profit, max_profit = 0, l = 0, r = 1;
        while (r < prices.size()) {
            profit = prices[r] - prices[l];
            if (profit > 0) {
                max_profit += profit;
            }
            l++;
            r++;
        }
        return max_profit;
    }
};
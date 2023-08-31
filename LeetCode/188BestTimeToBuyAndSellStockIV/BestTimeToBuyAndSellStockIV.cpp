class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // 2D DP -> Time:O(k*n), Space:O(k*n)
        vector<vector<int>> dp;
        int maxDiff, n = prices.size();
        for (int i = 0; i <= k; i++) {
            vector<int> temp(n, 0);
            dp.push_back(temp);
        }
        for (int i = 1; i < k+1; i++) {
            maxDiff = -prices[0];
            for (int j = 1; j < n; j++) {
                dp[i][j] = max(dp[i][j-1], prices[j] + maxDiff);
                maxDiff = max(maxDiff, dp[i-1][j] - prices[j]);
            }
        }
        return dp[k][n-1];
    }
};

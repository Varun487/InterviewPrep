class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // 2D DP -> Time:O(m*n), Space:O(m*n)
        int ans = 0;
        vector<vector<int>> dp;
        for (int i = 0; i < matrix.size()+1; i++) {
            vector<int> temp(matrix[0].size()+1, 0);
            dp.push_back(temp);
        }
        for (int i = 1; i < matrix.size()+1; i++) {
            for (int j = 1; j < matrix[0].size()+1; j++) {
                if (matrix[i-1][j-1] == '1') {
                    int tempMin = min(dp[i-1][j], dp[i][j-1]);
                    tempMin = min(tempMin, dp[i-1][j-1]);
                    dp[i][j] = 1 + tempMin;
                    if (dp[i][j] > ans) {
                        ans = dp[i][j];
                    }
                }
            }
        }
        return ans*ans;
    }
};

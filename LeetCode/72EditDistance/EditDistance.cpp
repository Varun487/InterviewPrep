class Solution {
public:
    int minDistance(string word1, string word2) {
        // 2D DP -> Time:O(n*m), Space:O(n*m)
        vector<vector<int>> dp;
        for (int i = 0; i < word1.size()+1; i++) {
            vector<int> temp(word2.size()+1, 0);
            dp.push_back(temp);
        }
        for (int i = word1.size(); i > -1; i--) {
            for (int j = word2.size(); j > -1; j--) {
                if (i == word1.size()) {
                    dp[i][j] = word2.size()-j;
                }
                else if (j == word2.size()) {
                    dp[i][j] = word1.size()-i;
                }
                else if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i+1][j+1];
                }
                else {
                    int tempMin = min(dp[i+1][j], dp[i][j+1]);
                    tempMin = min(tempMin, dp[i+1][j+1]);
                    dp[i][j] = 1 + tempMin;
                }
            }
        }
        return dp[0][0];
    }
};

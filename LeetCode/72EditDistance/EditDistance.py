class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        # 2D DP -> Time:O(n*m), Space:O(n*m)
        dp = [[0] * (len(word2)+1) for i in range(len(word1)+1)]
        for i in range(len(word1), -1, -1):
            for j in range(len(word2), -1, -1):
                if i == len(word1):
                    dp[i][j] = len(word2)-j
                elif j == len(word2):
                    dp[i][j] = len(word1)-i
                elif word1[i] == word2[j]:
                    dp[i][j] = dp[i+1][j+1]
                else:
                    dp[i][j] = 1 + min(dp[i+1][j], dp[i][j+1], dp[i+1][j+1])
        return dp[0][0]

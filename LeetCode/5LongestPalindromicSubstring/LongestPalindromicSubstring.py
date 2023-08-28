class Solution:
    def longestPalindrome(self, s: str) -> str:
        # 2D DP -> Time:O(n^2), Space:O(n^2)
        dp = [[0 for i in range(len(s))] for j in range(len(s))]
        for i in range(len(s)):
            for j in range(len(s)-i):
                if i == 0:
                    dp[j][i+j] = 1
                elif i == 1:
                    dp[j][i+j] = 1 if s[j] == s[i+j] else 0
                elif s[j] == s[j+i] and dp[j+1][i+j-1] == 1:
                        dp[j][i+j] = 1
        for i in range(len(s)):
            for j in range(i):
                if dp[j][len(s)-i+j]:
                    return s[j:len(s)-i+j+1]
        return s[0]

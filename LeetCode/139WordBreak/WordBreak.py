class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        # 1D DP -> Time:O(n*m*n), Space:O(m)
        dp = [False] * (len(s) + 1)
        dp[len(s)] = True
        for i in range(len(s) + 1, -1, -1):
            for w in wordDict:
                if (i + len(w)) <= len(s) and s[i:i+len(w)] == w:
                    dp[i] = dp[i + len(w)]
                    if dp[i]:
                        break
        return dp[0]

        # # Brute force / DFS -> Time:O(n^m*n), Space:O(m) -> m = Words in s, n = len(wordDict) -> Time limit exceeded
        # def dfs(current_string):
        #     if len(current_string) > len(s) or current_string != s[:len(current_string)]:
        #         return False
        #     if len(current_string) == len(s):
        #         return current_string == s
        #     for word in wordDict:
        #         if dfs(current_string + word):
        #             return True
        #     return False
        # for word in wordDict:
        #     if dfs(word):
        #         return True
        # return False

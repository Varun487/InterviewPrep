class Solution:
    def partition(self, s: str) -> List[List[str]]:
        # Backtracking -> Time:O(2^n), Space:O(n)
        ans = []
        part = []
        def dfs(i):
            if i >= len(s):
                ans.append(part.copy())
                return
            for j in range(i, len(s)):
                if s[i:j+1] == s[i:j+1][::-1]:
                    part.append(s[i:j+1])
                    dfs(j+1)
                    part.pop()
        dfs(0)
        return ans

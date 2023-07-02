class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        # Pointers -> Time: O(n), Space:O(1)
        i = 0
        j = 0
        n = len(s)
        m = len(t)
        while i < n and j < m:
            if s[i] == t[j]:
                i += 1
            j += 1
        if i == n:
            return True
        return False

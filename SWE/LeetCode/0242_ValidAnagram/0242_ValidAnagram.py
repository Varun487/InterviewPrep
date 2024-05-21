class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # Time: O(n + m), Space: O(n + m)
        s_d = {}
        for i in s:
            if i not in s_d:
                s_d[i] = 0
            s_d[i] += 1
        t_d = {}
        for i in t:
            if i not in t_d:
                t_d[i] = 0
            t_d[i] += 1
        return s_d == t_d

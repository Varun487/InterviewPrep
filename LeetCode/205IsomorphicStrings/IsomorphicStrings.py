class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        # 2 dictionaries -> Time:O(n), Space:O(n)
        s_d = {}
        t_d = {}
        for i in range(len(s)):
            if s[i] not in s_d and t[i] not in t_d:
                s_d[s[i]] = t[i]
                t_d[t[i]] = s[i]
            elif s[i] not in s_d or t[i] not in t_d:
                return False
            elif s_d[s[i]] != t[i] or t_d[t[i]] != s[i]:
                return False
        return True

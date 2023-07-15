class Solution:
    def minWindow(self, s: str, t: str) -> str:
        # Single Pass -> Time:O(n), Space:O(n)
        t_d = {}
        sub_str = {}
        for c in t:
            t_d[c] = 1 + t_d.get(c, 0)
        have, need = 0, len(t_d)
        l = 0
        res, res_len = [-1, -1], len(s)+1
        for r in range(len(s)):
            c = s[r]
            sub_str[c] = 1 + sub_str.get(c, 0)
            if c in t_d and sub_str[c] == t_d[c]:
                have += 1
            while have == need:
                if r-l+1 < res_len:
                    res = [l, r]
                    res_len = r-l+1
                sub_str[s[l]] -= 1
                if s[l] in t_d and sub_str[s[l]] < t_d[s[l]]:
                    have -= 1
                l += 1
        return s[res[0]:res[1]+1] if res_len != len(s)+1 else ""

        # # Brute Force -> Time:O(n^2), Space:O(n)
        # if len(t) > len(s):
        #     return ""
        # t_d = {}
        # for c in t:
        #     if c not in t_d:
        #         t_d[c] = 0
        #     t_d[c] += 1
        # for i in range(len(t), len(s)+1):
        #     for j in range(len(s)-i+1):
        #         sub_str_d = {}
        #         sub_str = s[j:j+i]
        #         for c in sub_str:
        #             if c not in sub_str_d:
        #                 sub_str_d[c] = 0
        #             sub_str_d[c] += 1
        #         min_window = True
        #         for c in t_d:
        #             if c not in sub_str_d:
        #                 min_window = False
        #             elif sub_str_d[c] < t_d[c]:
        #                 min_window = False
        #         if min_window:
        #             return sub_str
        # return ""

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # Sorting -> Time:O(slog(s)+tlog(t)), Space:O(1) ~ optimized, O(n) ~ worst case
        return sorted(s) == sorted(t)

        # Pythonic -> Time:O(s+t), Space:O(s+t) [worst case]
        return Counter(s) == Counter(t)

        # 2 dictionaries -> Time:O(s+t), Space:O(s+t) [worst case]
        s_d = {}
        t_d = {}
        for i in s:
            if i not in s_d:
                s_d[i] = 0
            s_d[i] += 1
        for j in t:
            if j not in t_d:
                t_d[j] = 0
            t_d[j] += 1
        return s_d == t_d

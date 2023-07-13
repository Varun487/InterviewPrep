class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        # 2 hashmaps optimized -> Time:O(n+m), Space:O(n+m)
        p_s = {}
        s_p = {}
        s_words = s.split(' ')
        if len(pattern) != len(s_words):
            return False
        for i in range(len(pattern)):
            if pattern[i] in p_s and p_s[pattern[i]] != s_words[i]:
                return False
            if s_words[i] in s_p and s_p[s_words[i]] != pattern[i]:
                return False
            p_s[pattern[i]] = s_words[i]
            s_p[s_words[i]] = pattern[i]
        return True

        # # 2 hashmaps -> Time:O(n+m), Space:O(n+m)
        # p_s = {}
        # s_p = {}
        # s_words = s.split(' ')
        # if len(pattern) != len(s_words):
        #     return False
        # for i in range(len(pattern)):
        #     if pattern[i] not in p_s and s_words[i] not in s_p:
        #         p_s[pattern[i]] = s_words[i]
        #         s_p[s_words[i]] = pattern[i]
        #     elif pattern[i] in p_s and s_words[i] not in s_p:
        #         return False
        #     elif pattern[i] not in p_s and s_words[i] in s_p:
        #         return False
        #     elif p_s[pattern[i]] != s_words[i] or s_p[s_words[i]] != pattern[i]:
        #         return False
        # return True

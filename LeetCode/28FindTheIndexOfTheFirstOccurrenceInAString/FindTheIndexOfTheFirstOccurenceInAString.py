class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        # Pythonic -> Time:O(nm), Space:O(1)
        if needle == '':
            return 0
        if haystack == '':
            return -1
        for i in range(len(haystack) - len(needle) + 1):    
            if needle == haystack[i:len(needle)+i]:
                return i
        return -1

        # # Double pass -> Time:O(nm), Space:O(1) [FASTER]
        # i = 0
        # while i < len(haystack):
        #     start = 0
        #     while start < len(needle) and start+i < len(haystack) and haystack[start+i] == needle[start]:
        #         start += 1
        #     if start == len(needle):
        #         return i
        #     i += 1
        # return -1

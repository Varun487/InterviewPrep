class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        # More elegant -> Time:O(nm), Space:O(1)
        longest_common_prefix = ""
        for i in range(len(strs[0])):
            for string in strs:
                if i == len(string) or string[i] != strs[0][i]:
                    return longest_common_prefix
            longest_common_prefix += strs[0][i]
        return longest_common_prefix

        # # Brute force -> Time:O(nm), Space:O(1)
        # longest_common_prefix = ""
        # n = len(strs)
        # m = len(strs[0])
        # for string in strs:
        #     if len(string) < m:
        #         m = len(string)
        # i = 0
        # while i < m:
        #     if len(strs[0]) <= i:
        #         return longest_common_prefix
        #     char = strs[0][i]
        #     for string in strs:
        #         if string[i] != char:
        #             return longest_common_prefix                    
        #     i += 1
        #     longest_common_prefix += char
        # return longest_common_prefix

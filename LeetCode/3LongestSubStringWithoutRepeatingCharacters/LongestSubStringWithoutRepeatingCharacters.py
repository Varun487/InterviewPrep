class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # sliding window -> Time:O(n), Space:O(n)
        c = set()
        l = 0
        ans = 0
        for r in range(len(s)):
            while s[r] in c:
                c.remove(s[l])
                l += 1
            c.add(s[r])
            ans = max(ans, r-l+1)
        return ans

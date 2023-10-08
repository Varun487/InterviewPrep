class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        # Sliding window -> Time:O(n), Space:O(1)
        ans = 0
        l = 0
        count = [0] * 26
        for r in range(len(s)):
            count[ord(s[r]) - ord('A')] += 1
            while r-l+1 - max(count) > k:
                count[ord(s[l]) - ord('A')] -= 1
                l += 1
            ans = max(ans, r-l+1)
        return ans

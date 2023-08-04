class Solution:
    def hammingWeight(self, n: int) -> int:
        # Bit Manipulation -> Time:O(1), Space:O(1)
        ans = 0
        for i in range(32):
            ans += (n>>i) & 1
        return ans

class Solution:
    def convert(self, s: str, numRows: int) -> str:
        # String manipulation -> Time:O(n), Space:O(n)
        if numRows == 1:
            return s
        ans = ""
        increment = (numRows - 1)*2
        for r in range(numRows):
            for i in range(r, len(s), increment):
                ans += s[i]
                if r > 0 and r < numRows - 1 and i + increment - 2*r < len(s):
                    ans += s[i + increment - 2*r]
        return ans

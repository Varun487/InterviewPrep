class Solution:
    def mySqrt(self, x: int) -> int:
        # Binary Search -> Time:O(log(n)), Space:O(1)
        l, r = 0, x
        ans = 0
        while l <= r:
            m = (l + r)//2
            if m**2 > x:
                r = m-1
            elif m**2 < x:
                l = m+1
                ans = m
            else:
                return m
        return ans

        # # Naive Solution -> Time:O(sqrt(n)), Space:O(1)
        # for i in range(1, x+1):
        #     m = i*i
        #     if m == x:
        #         return i
        #     elif m > x:
        #         return i - 1
        # return 0

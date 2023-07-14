class Solution:
    def myPow(self, x: float, n: int) -> float:
        # Divide and conquer -> Time:O(log(n)), Space:O(1)
        def helper(x, n):
            if x == 0: return 0
            if n == 0: return 1
            res = helper(x, n//2)
            res = res * res
            return x * res if n%2 else res
        res = helper(x, abs(n))
        return res if n>= 0 else 1/res
        
        # # Brute Force -> Time:O(n), Space:O(1)
        # ans = 1
        # for i in range(abs(n)):
        #     ans *= x
        # if n < 0:
        #     return 1/ans
        # return ans

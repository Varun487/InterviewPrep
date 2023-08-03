class Solution:
    def trailingZeroes(self, n: int) -> int:
        # Divide by 5 -> Time:O(logn), Space:O(1)
        ans = 0
        i = 1
        while n >= 5**i:
            ans += n//(5**i)
            i += 1
        return ans
        
        # # Brute force -> Time:O(n), Space:O(1)
        # twos = 0
        # fives = 0
        # if n > 1:
        #     for i in range(1, n+1):
        #         while i%5 == 0:
        #             fives += 1
        #             i = i//5
        #         while i%2 == 0:
        #             twos += 1
        #             i = i//2
        # return min(fives, twos)

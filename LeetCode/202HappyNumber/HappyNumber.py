class Solution:
    def isHappy(self, n: int) -> bool:
        # Run Till Cycle -> Time:O(n), Space:O(n)
        seen_nums = set()
        while n not in seen_nums:
            seen_nums.add(n)
            num_sum = 0
            while n != 0:
                num_sum += (n%10)**2
                n = n//10
            n = num_sum
        if n == 1:
            return True
        return False

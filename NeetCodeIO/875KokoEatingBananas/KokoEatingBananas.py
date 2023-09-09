import math

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        # Binary Search -> Time:O(n*log(max(piles))), Space:O(1)
        l, r = 1, max(piles)
        ans = r
        while l <= r:
            mid = (l+r) // 2
            s = 0
            for i in range(len(piles)):
                s += math.ceil(piles[i] / mid)
            if s <= h:
                ans = min(ans, mid)
                r = mid - 1
            else:
                l = mid + 1
        return ans

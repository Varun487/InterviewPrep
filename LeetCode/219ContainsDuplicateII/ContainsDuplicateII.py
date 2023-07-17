class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        # 2 passes -> Time:O(n), Space:O(n)
        s = set()
        l, r = 0, 0
        while r < len(nums):
            while r - l <= k and r < len(nums):
                if nums[r] in s:
                    return True
                s.add(nums[r])
                r += 1
            if r == len(nums):
                return False
            s.remove(nums[l])
            l += 1
        return False

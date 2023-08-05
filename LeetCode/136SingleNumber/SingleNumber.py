class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        # Bit Manipulation -> Time:O(n), Space:O(1)
        ans = nums[0]
        for i in range(1, len(nums)):
            ans ^= nums[i]
        return ans

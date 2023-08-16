class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # Single pass -> Time:O(n), Space:O(1)
        ans = nums[0]
        curr_sum = 0
        for i in nums:
            if curr_sum < 0:
                curr_sum = 0
            curr_sum += i
            ans = max(ans, curr_sum)
        return ans

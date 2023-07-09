class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        # 2 pointers -> Time:O(n), Space:O(1)
        l, total = 0, 0
        ans = len(nums) + 1
        for r in range(len(nums)):
            total += nums[r]
            while total >= target:
                ans = min(ans, r-l+1)
                total -= nums[l]
                l += 1
        return ans if ans < len(nums) + 1 else 0

        # # Brute Force -> Time:O(n^2), Space:O(1)
        # for window in range(1, len(nums)+1):
        #     for i in range(len(nums) - window + 1):
        #         if sum(nums[i:i+window]) == target:
        #             return window
        # return 0

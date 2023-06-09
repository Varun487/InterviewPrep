class Solution:
    def canJump(self, nums: List[int]) -> bool:
        # Greedy -> Time: O(n), Space: O(1)
        end = len(nums) - 1
        for i in range(end, -1, -1):
            if i + nums[i] >= end:
                end = i        
        return end == 0

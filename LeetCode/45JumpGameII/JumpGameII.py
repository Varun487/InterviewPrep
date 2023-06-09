class Solution:
    def jump(self, nums: List[int]) -> int:
        # Greedy -> Time: O(n), Space: O(1)
        jumps = 0
        l, r = 0, 0
        while r < len(nums) - 1:
            longest_jump = 0
            for i in range(l, r+1):
                longest_jump = max(longest_jump, i + nums[i])
            l = r + 1
            r = longest_jump
            jumps += 1
        return jumps

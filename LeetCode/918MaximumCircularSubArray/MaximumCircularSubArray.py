lass Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        # Kadane's algorithm -> Time:O(n), Space:O(1)
        global_max, global_min = nums[0], nums[0]
        curr_max, curr_min, total = 0, 0, 0
        for i in nums:
            curr_max = max(curr_max + i, i)
            curr_min = min(curr_min + i, i)
            total += i
            global_max = max(global_max, curr_max)
            global_min = min(global_min, curr_min)
        return max(global_max, total - global_min) if global_max >= 0 else global_max

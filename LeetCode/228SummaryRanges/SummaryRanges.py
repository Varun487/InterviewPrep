class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        # Single pass -> Time:O(n), Space:O(n)
        ans = []
        i = 0
        while i < len(nums):
            start = i
            end = i
            while i+1 < len(nums) and nums[i+1] - nums[i] == 1:
                end += 1
                i += 1
            if start == end:
                ans.append(str(nums[i]))
            else:
                ans.append(f"{nums[start]}->{nums[end]}")
            i += 1
        return ans

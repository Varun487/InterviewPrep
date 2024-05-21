class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # Time: O(n), Space: O(n)
        d = {}
        for i in range(len(nums)):
            sub = target - nums[i]
            if sub in d:
                return [i, d[sub]]
            d[nums[i]] = i
        return [0, 0]

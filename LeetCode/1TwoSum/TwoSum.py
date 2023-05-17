class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # Hash map -> O(n)
        d = {}
        for i in range(len(nums)):
            subtract = target - nums[i]
            if subtract in d:
                return [d[subtract], i]
            d[nums[i]] = i
        return [0, 0]
        
        # # Brute force -> O(n^2)
        # for i in range(len(nums)-1):
        #     for j in range(i+1, len(nums)):
        #         if nums[i] + nums[j] == target:
        #             return [i, j]
        # return [0, 0]

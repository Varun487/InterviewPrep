class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        # Partition method -> Time: O(n), Space: O(1)
        k = 0
        d = {}
        for i in range(len(nums)):
            if nums[i] not in d:
                d[nums[i]] = 1
                nums[k] = nums[i]
                k += 1
            elif d[nums[i]] < 2:
                d[nums[i]] += 1
                nums[k] = nums[i]
                k += 1
        return k
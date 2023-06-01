class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        # Partition method -> Time: O(n), Space: O(1)
        k = 0
        s = set()
        for i in range(len(nums)):
            if nums[i] not in s:
                nums[k] = nums[i]
                s.add(nums[i])
                k += 1
        return k

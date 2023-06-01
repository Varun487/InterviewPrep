class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        # Partition method -> Time: O(n), Space: O(1)
        k = 0
        for i in range(len(nums)):
            if nums[i] != val:
                nums[k] = nums[i]
                k += 1
        return k

        # # Brute force -> Time: O(n^2), Space: O(1)
        # while val in nums:
        #     nums.remove(val)
        # return len(nums)

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        # Binary Search -> Time:O(logn), Space:O(1)
        start, end = 0, len(nums)-1
        mid = end//2
        while start < end:
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                end = mid - 1
            else:
                start = mid + 1
            mid = (end - start)//2 + start
        if nums[start] < target:
            return start+1
        return start

        # # Single pass -> Time:O(n), Space:O(1)
        # i = 0
        # while i < len(nums):
        #     if nums[i] >= target:
        #         return i
        #     i += 1
        # return i

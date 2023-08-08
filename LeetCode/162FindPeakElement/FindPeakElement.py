lass Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        # Binary Search -> Time:O(log(n)), Space:O(1)
        start = 0
        end = len(nums)-1
        while start <= end:
            mid = (start + end) // 2
            if mid > 0 and nums[mid] < nums[mid - 1]:
                end = mid - 1
            elif mid < len(nums) - 1 and nums[mid] < nums[mid + 1]:
                start = mid + 1
            else:
                return mid
        return -1

        # # Brute force -> Time:O(n), Space:O(1)
        # for i in range(len(nums)):
        #     if (i == 0 and (len(nums) == 1 or nums[i] > nums[i+1])):
        #         return i
        #     elif i == len(nums)-1 and nums[i] > nums[i-1]:
        #         return i
        #     elif nums[i] > nums[i-1] and nums[i] > nums[i+1]:
        #         return i
        # return -1

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # Binary Search -> Time:O(log(m)+log(n)), Space:O(1)
        start, end = 0, len(nums)-1
        while start <= end:
            mid = (start + end) // 2
            if target == nums[mid]:
                return mid
            if nums[mid] >= nums[start]:
                if target < nums[start] or target > nums[mid]:
                    start = mid + 1
                else:
                    end = mid - 1
            else:
                if target < nums[mid] or target > nums[end]:
                    end = mid - 1
                else:
                    start = mid + 1
        return -1

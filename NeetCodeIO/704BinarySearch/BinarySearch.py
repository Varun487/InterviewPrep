class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # Binary Search -> Time:O(log(n)), Space:O(1)
        start, end = 0, len(nums)-1
        while start <= end:
            mid = end+start // 2
            if nums[mid] < target:
                start = mid + 1
            elif nums[mid] > target:
                end = mid - 1
            else:
                return mid
        return -1

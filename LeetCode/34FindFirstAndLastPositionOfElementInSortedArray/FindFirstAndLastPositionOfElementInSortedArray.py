class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        # Binary Search -> Time:O(logn), Space:O(1)
        def binary_search(nums, target, check_left=True):
            start, end = 0, len(nums)-1
            i = -1
            while start <= end:
                mid = (start+end)//2
                if target > nums[mid]:
                    start = mid + 1
                elif target < nums[mid]:
                    end = mid - 1
                else:
                    i = mid
                    if check_left:
                        end = mid - 1
                    else:
                        start = mid + 1
            return i
        return [binary_search(nums, target), binary_search(nums, target, False)]

import heapq

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        # Heap -> Time:O(n+klog(n)), Space:O(n)
        arr = [-elem for elem in nums]
        heapq.heapify(arr)
        for i in range(k-1):
            heapq.heappop(arr)
        return -heapq.heappop(arr)

        # # Sort array -> Time:O(nlog(n)), Space:O(1)
        # return sorted(nums)[-k]

        # # Quick Select -> Time:O(n) avg, O(n^2) worst, Space:O(1) -> Time Limit Exceeded
        # k = len(nums)-k
        # def quick_select(l, r):
        #     pivot, p = nums[r], l
        #     for i in range(l, r):
        #         if nums[i] <= pivot:
        #             nums[p], nums[i] = nums[i], nums[p]
        #             p += 1
        #     nums[p], nums[r] = nums[r], nums[p]
        #     if p > k:
        #         return quick_select(l, p-1)
        #     elif p < k:
        #         return quick_select(p+1, r)
        #     else:
        #         return nums[p]
        # return quick_select(0, len(nums)-1)

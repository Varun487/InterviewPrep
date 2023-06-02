class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # Reverse -> Time: O(n), Space:O(1)
        k = k%len(nums)
        l, r = 0, len(nums)-1
        while l<r:
            nums[l], nums[r] = nums[r], nums[l]
            l += 1
            r -= 1
        l, r = 0, k-1
        while l<r:
            nums[l], nums[r] = nums[r], nums[l]
            l += 1
            r -= 1
        l, r = k, len(nums)-1
        while l<r:
            nums[l], nums[r] = nums[r], nums[l]
            l += 1
            r -= 1
        
        # # Temp array -> Time: O(n), Space:O(n)
        # n = len(nums)
        # new_nums = [0 for i in range(n)]
        # for i in range(n):
        #     new_nums[(i+k)%n] = nums[i]
        # for i in range(n):
        #     nums[i] = new_nums[i]

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        # Partition method -> Time: O(n), Space: O(1)
        k = 1
        for i in range(1, len(nums)):
            if nums[i] != nums[i-1]:
                nums[k] = nums[i]
                k += 1
        return k

        # # Brute Force: Time: O(n), Space: O(n)
        # k = 0
        # s = set()
        # for i in range(len(nums)):
        #     if nums[i] not in s:
        #         nums[k] = nums[i]
        #         s.add(nums[i])
        #         k += 1
        # return k

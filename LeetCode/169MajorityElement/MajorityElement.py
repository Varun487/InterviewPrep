class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        # Boyer-Moore alorithm
        res = nums[0]
        count = 0
        for i in range(len(nums)):
            print(count, res)
            if count == 0 or nums[i] == res:
                res = nums[i]
                count += 1
            else:
                count -= 1
        return res

        # # HashMap method -> Time: O(n), Space: O(n)
        # d = {}
        # n = len(nums)
        # majority = n//2
        # if n%2:
        #     majority += 1
        # for i in range(n):
        #     if nums[i] not in d:
        #         d[nums[i]] = 0
        #     d[nums[i]] += 1
        #     if d[nums[i]] >= majority:
        #         return nums[i]

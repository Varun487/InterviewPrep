class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        # HashSet -> Time:O(n), Space:O(n)
        s = set(nums)
        ans = 0
        for i in range(len(nums)):
            curr_seq = 0
            curr_num = nums[i]
            if curr_num - 1 not in s:
                curr_seq = 1
                while curr_num + 1 in s:
                    curr_num += 1
                    curr_seq += 1
            if curr_seq > ans:
                ans = curr_seq
        return ans

class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        # Single pass -> Time:O(n), Space:O(n)
        ans = []
        start = 0
        curr_ans = ''
        for i in range(len(nums)):
            if not curr_ans:
                start = i
                curr_ans += str(nums[i])
            if i + 1 < len(nums):
                if nums[i] + 1 != nums[i+1]:
                    if start != i:
                        curr_ans += '->' + str(nums[i])
                    ans.append(curr_ans)
                    curr_ans = ''
        if curr_ans:
            if start != len(nums)-1:
                curr_ans += '->' + str(nums[len(nums)-1])
            ans.append(curr_ans)
        return ans

        # # Single pass -> Time:O(n), Space:O(n)
        # ans = []
        # i = 0
        # while i < len(nums):
        #     start = i
        #     end = i
        #     while i+1 < len(nums) and nums[i+1] - nums[i] == 1:
        #         end += 1
        #         i += 1
        #     if start == end:
        #         ans.append(str(nums[i]))
        #     else:
        #         ans.append(f"{nums[start]}->{nums[end]}")
        #     i += 1
        # return ans

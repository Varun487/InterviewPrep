class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        # 2 pointers -> Time:O(n), Space:O(n)
        ans, q, l, r = [], [], 0, 0
        while r < len(nums):
            while q and nums[q[-1]] < nums[r]:
                q.pop()
            q.append(r)
            if l > q[0]:
                q.pop(0)
            if r + 1 >= k:
                ans.append(nums[q[0]])
                l += 1
            r += 1
        return ans

        # # Brute Force -> Time:O(n*k), Space:O(n) -> Time Limit exceeded
        # curr_max, ans = nums[0], []
        # for i in range(0, len(nums)-k+1):
        #     curr_max = max(nums[i:i+k])
        #     ans.append(curr_max)
        # return ans

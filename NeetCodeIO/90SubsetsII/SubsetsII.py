class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        # Backtracking -> Time:O(2^n), Space:O(n)
        nums.sort()
        ans = []
        def dfs(i, sub):
            if i >= len(nums):
                ans.append(sub.copy())
                return
            sub.append(nums[i])
            dfs(i+1, sub.copy())
            sub.pop()
            while i + 1 < len(nums) and nums[i] == nums[i+1]:
                i += 1
            dfs(i+1, sub.copy())
        dfs(0, [])
        return ans

        # # Backtracking + set -> Time:O(2^n), Space:O(n)
        # nums.sort()
        # ans = set()
        # def dfs(i, sub):
        #     if i >= len(nums):
        #         ans.add(tuple(sub.copy()))
        #         return
        #     dfs(i+1, sub.copy())
        #     sub.append(nums[i])
        #     dfs(i+1, sub.copy())
        # dfs(0, [])
        # return list(ans)

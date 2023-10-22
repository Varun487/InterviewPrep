class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        # Backtracking -> Time:O(2^n), Space:O(n)
        ans = []
        def dfs(i, sub):
            if i >= len(nums):
                ans.append(sub.copy())
                return
            dfs(i+1, sub.copy())
            sub.append(nums[i])
            dfs(i+1, sub.copy())
        dfs(0, [])
        return ans

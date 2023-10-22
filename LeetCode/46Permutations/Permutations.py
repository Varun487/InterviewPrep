class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        # Backtracking -> Time:O(n*n!), Space:O(n!) n=len(nums)
        ans = []
        def dfs(perm, visited):
            if len(perm) == len(nums):
                ans.append(perm)
                return
            for i in range(len(nums)):
                if i not in visited:
                    visited.add(i)
                    perm.append(nums[i])
                    dfs(perm.copy(), visited.copy())
                    perm.pop()
                    visited.remove(i)
        dfs([], set())
        return ans

        # # Backtracking -> Time:O(n*n!), Space:O(n!) n=len(nums)
        # ans = []
        # if len(nums) == 1:
        #     return [nums[:]]
        # for i in range(len(nums)):
        #     n = nums.pop(0)
        #     perms = self.permute(nums)
        #     for perm in perms:
        #         perm.append(n)
        #     ans.extend(perms)
        #     nums.append(n)
        # return ans

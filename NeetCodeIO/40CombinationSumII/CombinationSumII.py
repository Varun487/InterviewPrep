class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        # Sort + DFS -> Time:O(2^n), Space:O(n)
        candidates.sort()
        ans = set()
        def dfs(vals, currSum, i):
            currSum += candidates[i]
            if currSum > target:
                return
            vals.append(candidates[i])
            if currSum == target:
                ans.add(tuple(vals))
                return
            prev = -1
            for j in range(i+1, len(candidates)):
                if candidates[j] != prev:
                    dfs(vals.copy(), currSum, j)
                prev = candidates[j]
        for i in range(len(candidates)):
            dfs([], 0, i)
        return list(ans)

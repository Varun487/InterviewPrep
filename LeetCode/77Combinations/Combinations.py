class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        # Backtracking -> Time:O(n^k), Space:O(k)
        ans = []
        def backtrack(start_num, curr):
            if len(curr) == k:
                ans.append(curr)
                return
            for i in range(start_num, n+1):
                backtrack(i+1, curr + [i])
        backtrack(1, [])
        return ans

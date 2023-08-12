class Solution:
    def totalNQueens(self, n: int) -> int:
        # Backtracking -> Time:O(n^n), Space:O(n)
        col = set()
        pos_diag = set()
        neg_diag = set()
        ans = 0
        def backtrack(r):
            if r == n:
                nonlocal ans
                ans += 1
                return
            for c in range(n):
                if c not in col and (r + c) not in pos_diag and (r - c) not in neg_diag:
                    col.add(c)
                    pos_diag.add(r+c)
                    neg_diag.add(r-c)
                    backtrack(r+1)
                    col.remove(c)
                    pos_diag.remove(r+c)
                    neg_diag.remove(r-c)
        backtrack(0)
        return ans

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        # Backtracking -> Time:O(n*4^n), Space:O(n*4^n)
        d = {
            "2":"abc",
            "3":"def",
            "4":"ghi",
            "5":"jkl",
            "6":"mno",
            "7":"pqrs",
            "8":"tuv",
            "9":"wxyz",
        }
        ans = []
        def backtrack(i, curr):
            if len(curr) == len(digits):
                ans.append(curr)
                return
            for c in d[digits[i]]:
                backtrack(i+1, curr+c)
        if digits:
            backtrack(0, "")
        return ans

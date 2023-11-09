class Solution:
    ans = 0

    def dfs(self, curr, n):
        if curr == n:
            self.ans += 1
            return
        elif curr > n:
            return
        self.dfs(curr+1, n)
        self.dfs(curr+2, n)
    
    def climbStairs(self, n: int) -> int:
        # # DFS -> Time:O(2^n), Space:O(n)
        # self.dfs(0, n)
        # return self.ans
        
        # Fibonacci series -> Time:O(n), Space:O(1)
        one, two = 1, 1
        for i in range(n-1):
            temp = one
            one += two
            two = temp
        return one

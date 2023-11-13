class Solution:
    minCost = float('inf')

    def dfs(self, start, cost, curr_cost):
        if start >= len(cost):
            self.minCost = min(self.minCost, curr_cost)
            return
        self.dfs(start+1, cost, curr_cost+cost[start])
        self.dfs(start+2, cost, curr_cost+cost[start])

    def minCostClimbingStairs(self, cost: List[int]) -> int:
        # 1 DP -> Time: O(n), Space: O(n)
        dp = [float('inf')] * len(cost)
        dp[-1] = cost[-1]
        dp[-2] = cost[-2]
        for i in range(-3, -len(cost)-1, -1):
            dp[i] = cost[i] + min(dp[i+1], dp[i+2])
        print(dp)
        return min(dp[0], dp[1])

        # # DFS -> Time: O(2^n), Space:O(n) -> Time Limit Exceeded
        # self.dfs(0, cost, 0)
        # self.dfs(1, cost, 0)
        # return self.minCost

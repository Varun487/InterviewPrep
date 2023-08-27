class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        # 1D DP -> Time:O(n^2), Space:O(n)
        ans = [0] * (len(triangle)+1)
        for i in range(len(triangle)-1, -1, -1):
            for j in range(i+1):
                ans[j] = triangle[i][j] + min(ans[j], ans[j+1])
        return ans[0]

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        # DFS -> Time:O(4^mn*mn), Space:O(mn)
        ans = 0
        visited = set()

        def dfs(r, c):
            if r >= 0 \
                and c >= 0 \
                and r < len(grid) \
                and c < len(grid[0]) \
                and (r,c) not in visited \
                and grid[r][c] == 1:
                visited.add((r,c))
                return 1 + dfs(r-1, c) + dfs(r, c-1) + dfs(r+1, c) + dfs(r, c+1)
            return 0

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1 and (i,j) not in visited:
                    area = dfs(i,j)
                    ans = max(ans, area)

        return ans

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        # DFS -> Time:O(nm), Space:O(nm)
        ans = 0
        visited = set()

        def dfs(r, c):
            if r >= 0 and \
                c >= 0 and \
                r < len(grid) and \
                c < len(grid[0]) and \
                (r, c) not in visited and \
                grid[r][c] == '1':
                visited.add((r, c))
                dfs(r+1, c)
                dfs(r, c+1)
                dfs(r-1, c)
                dfs(r, c-1)

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1' and (i, j) not in visited:
                    ans += 1
                    dfs(i, j)

        return ans

        # # BFS -> Time:O(nm), Space:O(nm)
        # if not grid:
        #     return 0
        # visited = set()
        # ans = 0
        # def bfs(r,c):
        #     q = []
        #     q.append((r,c))
        #     while q:
        #         row,col = q.pop(0)
        #         directions = [[-1,0], [1,0], [0, 1], [0, -1]]
        #         for dr,dc in directions:
        #             r, c = row+dr, col+dc
        #             if (r in range(len(grid)) and
        #                 c in range(len(grid[0])) and
        #                 grid[r][c] == "1" and 
        #                 (r,c) not in visited):
        #                 q.append((r,c))
        #                 visited.add((r,c))
        # for r in range(len(grid)):
        #     for c in range(len(grid[0])):
        #         if (r,c) not in visited and grid[r][c] == "1":
        #             bfs(r,c)
        #             visited.add((r,c))
        #             ans += 1
        # return ans

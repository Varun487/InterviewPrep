class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        # BFS -> Time:O(mn), Space:O(mn)
        q = []
        time, fresh = 0, 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 2:
                    q.append((i,j))
                if grid[i][j] == 1:
                    fresh += 1
        directions = ((1, 0),(-1, 0),(0, 1),(0, -1))
        while q and fresh > 0:
            for _ in range(len(q)):
                r, c = q.pop(0)
                for dr, dc in directions:
                    row, col = r + dr, c + dc
                    if row < 0 or col < 0 or row >= len(grid) or col >= len(grid[0]) or grid[row][col] != 1:
                        continue
                    q.append((row, col))
                    grid[row][col] = 2
                    fresh -= 1
            time += 1
        return time if fresh == 0 else -1

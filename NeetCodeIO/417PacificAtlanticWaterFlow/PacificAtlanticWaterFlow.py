class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        # DFS -> Time:O((mn)^2), Space:O(mn)
        ans = []
        pac, atl = set(), set()

        def dfs(r, c, visit, prev):
            if (r, c) in visit or \
                r < 0 or r >= len(heights) or \
                c < 0 or c >= len(heights[0]) or \
                heights[r][c] < prev:
                return
            visit.add((r, c))
            dfs(r + 1, c, visit, heights[r][c])
            dfs(r - 1, c, visit, heights[r][c])
            dfs(r, c + 1, visit, heights[r][c])
            dfs(r, c - 1, visit, heights[r][c])
        
        for i in range(len(heights[0])):
            dfs(0, i, pac, heights[0][i])
            dfs(len(heights) - 1, i, atl, heights[len(heights) - 1][i])

        for i in range(len(heights)):
            dfs(i, 0, pac, heights[i][0])
            dfs(i, len(heights[0]) - 1, atl, heights[i][len(heights[0]) - 1])

        for i in pac:
            if i in atl:
                ans.append(i)
        
        return ans

class Solution:
    def same_values(self, grid):
        val = grid[0][0]
        for i in range(len(grid)):
            for j in range(len(grid)):
                if grid[i][j] != val:
                    return False
        return True
    def slice_grid(self, grid, i, j, k, l):
        new_grid = grid[i:j]
        for v in range(len(new_grid)):
            new_grid[v] = new_grid[v][k:l]
        return new_grid
    def construct(self, grid: List[List[int]]) -> 'Node':
        # Divide and Conquer -> Time:O(n*log(n)), Space:O(log(n))
        if self.same_values(grid):
            return Node(grid[0][0], 1, None, None, None, None)
        n = len(grid)
        new_node = Node(grid[0][0], 0, None, None, None, None)
        new_node.topLeft = self.construct(self.slice_grid(grid, 0, n//2, 0, n//2))
        new_node.topRight = self.construct(self.slice_grid(grid, 0, n//2, n//2, n))
        new_node.bottomLeft = self.construct(self.slice_grid(grid, n//2, n, 0, n//2))
        new_node.bottomRight = self.construct(self.slice_grid(grid, n//2, n, n//2, n))
        return new_node

class Solution {
public:
    int minSum = INT_MAX;
    void dfsPathSum(vector<vector<int>>& grid, int currentSum, int row, int col) {
        if (row >= grid.size() || col >= grid[0].size()) {
            return;
        }
        if (row == grid.size()-1 && col == grid[0].size()-1) {
            if (currentSum + grid[row][col] < minSum) {
                minSum = currentSum + grid[row][col];
            }
            return;
        }
        dfsPathSum(grid, currentSum+grid[row][col], row, col+1);
        dfsPathSum(grid, currentSum+grid[row][col], row+1, col);
    }
    int minPathSum(vector<vector<int>>& grid) {
        // 1D DP -> Time:O(n*m), Space:O(m)
        int rows = grid.size(), cols = grid[0].size();
        vector<int> ans(cols+1, INT_MAX);
        ans[cols-1] = 0;
        for (int i = rows - 1; i > -1; i--) {
            for (int j = cols - 1; j > -1; j--) {
                ans[j] = grid[i][j] + min(ans[j], ans[j+1]);
            }
        }
        return ans[0];

        // // 2D DP -> Time:O(n*m), Space:O(n*m)
        // int rows = grid.size(), cols = grid[0].size();
        // vector<vector<int>> ans;
        // for (int i = 0; i < rows + 1; i++) {
        //     vector<int> temp(cols+1, INT_MAX);
        //     ans.push_back(temp);
        // }
        // ans[rows][cols-1] = 0;
        // for (int i = rows - 1; i > -1; i--) {
        //     for (int j = cols - 1; j > -1; j--) {
        //         ans[i][j] = grid[i][j] + min(ans[i+1][j], ans[i][j+1]);
        //     }
        // }
        // return ans[0][0];

        // // Brute Force / DFS -> Time:O(2^n), Space:O(n+m-1) -> Time limit exceeded
        // dfsPathSum(grid, 0, 0, 0);
        // return minSum;
    }
};

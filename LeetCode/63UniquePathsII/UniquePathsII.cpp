class Solution {
public:
    int paths = 0;
    void dfsPaths(vector<vector<int>>& obstacleGrid, int row, int col) {
        if (row >= obstacleGrid.size() || col >= obstacleGrid[0].size()) {
            return;
        }
        if (row == obstacleGrid.size()-1 && col == obstacleGrid[0].size()-1) {
            paths++;
            return;
        }
        if (obstacleGrid[row][col] == 1) {
            return;
        }
        dfsPaths(obstacleGrid, row+1, col);
        dfsPaths(obstacleGrid, row, col+1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // 1D DP -> Time:O(n*m), Space:O(m)
        int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
        vector<long> ans(cols, 0);
        ans[cols-1] = 1;
        for (int i = rows-1; i > -1; i--) {
            for (int j = cols-1; j > -1; j--) {
                if (obstacleGrid[i][j]) {
                    ans[j] = 0;
                }
                else if (j+1 < cols) {
                    ans[j] = ans[j] + ans[j+1];
                }
            }
        }
        return ans[0];
        
        // // Brute Force / DFS -> Time:O(2^(n*m)), Space:O(n*m) -> Time Limit Exceeded
        // if (obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1] == 0) {
        //     dfsPaths(obstacleGrid, 0, 0);
        // }
        // return paths;
    }
};

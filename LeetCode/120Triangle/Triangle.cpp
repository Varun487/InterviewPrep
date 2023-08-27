class Solution {
public:
    int minSum = INT_MAX;
    void dfsMinTotal(vector<vector<int>>& triangle, int currentSum, int row, int index) {
        if (row >= triangle.size() || index >= triangle[row].size()) {
            return;
        }
        if (row == triangle.size()-1) {
            minSum = min(triangle[row][index] + currentSum, minSum);
        }
        dfsMinTotal(triangle, currentSum + triangle[row][index], row + 1, index);
        dfsMinTotal(triangle, currentSum + triangle[row][index], row + 1, index + 1);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        // 1D DP -> Time:O(n^2), Space:O(n)
        vector<int> ans(triangle.size()+1, 0);
        for (int i = triangle.size()-1; i > -1; i--) {
            for (int j = 0; j < i+1; j++) {
                ans[j] = triangle[i][j] + min(ans[j], ans[j+1]);
            }
        }
        return ans[0];

        // // 2D DP -> Time:O(n^2), Space:O(n^2)
        // vector<vector<int>> ans;
        // for (int i = 0; i <= triangle.size(); i++) {
        //     vector<int> temp(i+1, 0);
        //     ans.push_back(temp);
        // }
        // for (int i = triangle.size()-1; i > -1; i--) {
        //     for (int j = 0; j < i+1; j++) {
        //         ans[i][j] = triangle[i][j] + min(ans[i+1][j], ans[i+1][j+1]);
        //     }
        // }
        // return ans[0][0];

        // // Brute Force / DFS -> Time:O(2^n), Space:O(n) -> Time Limit exceeded
        // dfsMinTotal(triangle, 0, 0, 0);
        // return minSum;
    }
};

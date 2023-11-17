class Solution {
public:
    set<pair<int,int>> visited;
    int dfs(int r, int c, vector<vector<int>>& grid) {
        pair<int,int> temp(r, c);
        if (r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size() && visited.find(temp) == visited.end() 
        && grid[r][c] == 1) {
            visited.insert(temp);
            return 1 + dfs(r-1, c, grid) + dfs(r, c-1, grid) + dfs(r, c+1, grid) + dfs(r+1, c, grid);
        }
        return 0;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // DFS -> Time:O(4^mn*mn), Space:O(mn)
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                ans = max(ans, dfs(i,j, grid));
            }
        }
        return ans;
    }
};

class Solution {
public:
    int ans = 0;
    set<vector<int>> visited;
    vector<vector<int>> directions {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };
    void bfs(vector<vector<char>>& grid, vector<int> v) {
        queue<vector<int>> q;
        q.push(v);
        while (!q.empty()) {
            vector<int> current = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int row = directions[i][0] + current[0];
                int col = directions[i][1] + current[1];
                vector<int> temp;
                temp.push_back(row);
                temp.push_back(col);
                if (row >= 0 &&
                    row < grid.size() &&
                    col >= 0 &&
                    col < grid[0].size() &&
                    visited.find(temp) == visited.end() &&
                    grid[row][col] == '1') {
                        q.push(temp);
                        visited.insert(temp);
                    }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // BFS -> Time:O(nm), Space:O(nm)
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                vector<int> v;
                v.push_back(i);
                v.push_back(j);
                if (grid[i][j] == '1' && visited.find(v) == visited.end()) {
                    bfs(grid, v);
                    visited.insert(v);
                    ans++;
                }
            }
        }
        return ans;
    }
};

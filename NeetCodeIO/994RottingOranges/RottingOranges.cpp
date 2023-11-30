class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // BFS -> Time:O(mn), Space:O(mn)
        queue<pair<int,int>> q;
        int time = 0, fresh = 0;
        int ROWS = grid.size(), COLS = grid[0].size();
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 2) {
                    pair<int,int> temp(i,j);
                    q.push(temp);
                }
                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        vector<pair<int,int>> directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };;
        while (!q.empty() && fresh > 0) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                int row = q.front().first, col = q.front().second;
                q.pop();
                for (int j = 0; j < directions.size(); j++) {
                    int dr = directions[j].first, dc = directions[j].second;
                    int r = row + dr, c = col + dc;
                    if (r < 0 || c < 0 || r >= ROWS || c >= COLS || grid[r][c] != 1) {
                        continue;
                    }
                    grid[r][c] = 2;
                    fresh--;
                    pair<int,int> temp(r,c);
                    q.push(temp);
                }
            }
            time++;
        }
        if (fresh) {
            return -1;
        }
        return time;
    }
};

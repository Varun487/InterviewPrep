class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // 2 passes -> Time:O(mn), Space:O(1)
        int rows = board.size();
        int cols = board[0].size();
        int num_neighbours;
        set<int> s {1, 3};
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                num_neighbours = 0;
                for (int i = r-1; i < r+2; i++) {
                    for (int j = c-1; j < c+2; j++) {
                        if ((i == r && j == c) || i<0 || j<0 || i==rows || j==cols) {
                            continue;
                        }
                        if (s.find(board[i][j]) != s.end()) {
                            num_neighbours++;
                        }
                    }
                }
                if (board[r][c]) {
                    if (num_neighbours == 2 || num_neighbours == 3) {
                        board[r][c] = 3;
                    }
                }
                else if (num_neighbours == 3) {
                    board[r][c] = 2;
                }
            }
        }
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == 1) {
                    board[r][c] = 0;
                }
                else if (board[r][c] == 2 || board[r][c] == 3) {
                    board[r][c] = 1;
                }
            }
        }
    }
};

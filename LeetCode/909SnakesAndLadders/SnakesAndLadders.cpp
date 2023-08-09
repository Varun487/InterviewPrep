class Solution {
public:
    vector<int> squareToPos(int n, int square) {
        vector<int> pos;
        int r = (square - 1) / n;
        int c = (square - 1) % n;
        if (r%2) {
            c = n - 1 - c;
        }
        pos.push_back(r);
        pos.push_back(c);
        return pos;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        // BFS -> Time:O(n^2), Space:O(n^2)
        int next_square, n = board.size();
        queue<vector<int>> q;
        vector<int> square, pos, start{1, 0};
        set<int> visited;
        reverse(board.begin(), board.end());
        q.push(start);
        while (!q.empty()) {
            square = q.front();
            q.pop();
            for (int i = 1; i < 7; i++) {
                next_square = square[0] + i;
                pos = squareToPos(n, next_square);
                if (board[pos[0]][pos[1]] != -1) {
                    next_square = board[pos[0]][pos[1]];
                }
                if (next_square == n*n) {
                    return square[1] + 1;
                }
                if (visited.find(next_square) == visited.end()) {
                    visited.insert(next_square);
                    start[0] = next_square;
                    start[1] = square[1] + 1;
                    q.push(start);
                }
            }
        }
        return -1;
    }
};

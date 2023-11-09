class Solution {
public:
    set<vector<vector<string>>> ans_boards;
    void dfs(vector<vector<string>> board, int queens) {
        if (queens == board.size()) {
            ans_boards.insert(board);
            return;
        }
        int n = board.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == ".") {
                    dfs(place_queen(board, i, j), queens+1);
                }
            }
        }
    }
    vector<vector<string>> place_queen(vector<vector<string>> board, int i, int j) {
        int n = board.size();
        for (int k = 0; k < n; k++) {
            board[i][k] = "X";
            board[k][j] = "X";
            int left_diag_index = k+j-i;
            int right_diag_index = i+j-k;
            if (0 <= left_diag_index && left_diag_index < n) {
                board[k][left_diag_index] = "X";
            }
            if (0 <= right_diag_index && right_diag_index < n) {
                board[k][right_diag_index] = "X";
            }
        }
        board[i][j] = "Q";
        return board;
    }
    void print_board(vector<vector<string>> board) {
        int n = board.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    vector<vector<string>> solveNQueens(int n) {
        // Backtracking -> Time:O(n^2*2^n), Space:O(n^2*2^n) -> Time limit exceeded
        vector<vector<string>> board;
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            vector<string> row;
            for (int j = 0; j < n; j++) {
                row.push_back(".");
            }
            board.push_back(row);
        }
        dfs(board, 0);
        for (auto i: ans_boards) {
            vector<string> temp_board;
            for (int j = 0; j < n; j++) {
                string row = "";
                for (int k = 0; k < n; k++) {
                    if (i[j][k] == "Q") {
                        row += "Q";
                    }
                    else {
                        row += ".";
                    }
                }
                temp_board.push_back(row);
            }
            ans.push_back(temp_board);
        }
        return ans;
    }
};

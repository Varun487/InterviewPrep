class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Arrays -> Time:O(n^2), Space:O(n^2) n=SideOfBoard
        vector<vector<int> > rows(9, vector<int>(9, 0));
        vector<vector<int> > cols(9, vector<int>(9, 0));
        vector<vector<int> > boxes(9, vector<int>(9, 0));
        int box_index, num;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    box_index = (i/3 + j/3) + (i/3 * 2);
                    num = board[i][j] - '0' - 1;
                    if (rows[i][num] || cols[num][j] || boxes[box_index][num]) {
                        return false;
                    }
                    rows[i][num] = 1;
                    cols[num][j] = 1;
                    boxes[box_index][num] = 1;                    
                }
            }
        }
        return true;

        // // Single pass -> Time:O(n^2), Space:O(n^2) n=SideOfBoard
        // map<string, set<char> > m;
        // int box_index;
        // bool num_in_row, num_in_col, num_in_box;
        // for (int i = 0; i < 9; i++) {
        //     set<char> a;
        //     m["R"+to_string(i)] = a;
        //     set<char> b;
        //     m["C"+to_string(i)] = b;
        //     set<char> c;
        //     m["B"+to_string(i)] = c;
        // }
        // for (int i = 0; i < 9; i++) {
        //     for (int j = 0; j < 9; j++) {
        //         if (board[i][j] != '.') {
        //             box_index = (i/3 + j/3) + (i/3 * 2);
        //             num_in_row = m["R"+to_string(i)].find(board[i][j]) != m["R"+to_string(i)].end();
        //             num_in_col = m["C"+to_string(j)].find(board[i][j]) != m["C"+to_string(j)].end();
        //             num_in_box = m["B"+to_string(box_index)].find(board[i][j]) != m["B"+to_string(box_index)].end();
        //             if (num_in_row || num_in_col || num_in_box) {
        //                 return false;
        //             }
        //             m["R"+to_string(i)].insert(board[i][j]);
        //             m["C"+to_string(j)].insert(board[i][j]);
        //             m["B"+to_string(box_index)].insert(board[i][j]);
        //         }
        //     }
        // }
        // return true;
    }
};

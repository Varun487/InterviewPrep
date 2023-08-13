class Solution {
public:
    bool backtrack(vector<vector<char>>& board, string &word, set<vector<int>> &visited, int r, int c, int curr) {
        if (curr == word.size()) {
            return true;
        }
        vector<int> index;
        index.push_back(r);
        index.push_back(c);
        if (r < 0
            || c < 0
            || r >= board.size()
            || c >= board[0].size()
            || word[curr] != board[r][c]
            || visited.find(index) != visited.end()) {
                return false;
            }
        visited.insert(index);
        bool res = (backtrack(board, word, visited, r + 1, c, curr + 1)
                    || backtrack(board, word, visited, r - 1, c, curr + 1)
                    || backtrack(board, word, visited, r, c + 1, curr + 1)
                    || backtrack(board, word, visited, r, c - 1, curr + 1));
        visited.erase(index);
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        // DFS + Backtracking -> Time:O(n * m * 4^n), Space:O(m)
        set<vector<int>> visited;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (backtrack(board, word, visited, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};

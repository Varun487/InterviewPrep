from copy import deepcopy

class Solution:
    ans = set()

    def place_queen(self, board, i, j):
        n = len(board)
        board = list(board)
        for k in range(n):
            board[i][k] = 'X'
            board[k][j] = 'X'
            if 0 <= k+j-i < n:
                board[k][k+j-i] = 'X'
            if 0 <= i+j-k < n:
                board[k][j+i-k] = 'X'
        board[i][j] = 'Q'
        return board

    def dfs(self, n, board, queens):
        if queens == n:
            self.ans.add(tuple(tuple(i) for i in board))
            return
        for i in range(n):
            for j in range(n):
                if board[i][j] == ".":
                    self.dfs(n, self.place_queen(deepcopy(board), i, j), queens+1)

    def solveNQueens(self, n: int) -> List[List[str]]:
        # Backtracking -> Time:O(n^2*2^n), Space:O(n^2*2^n) -> Time limit exceeded
        self.ans = set()
        board = [['.']*n for i in range(n)]
        self.dfs(n, deepcopy(board), 0)
        build_ans = []
        for board in self.ans:
            b = []
            for row in board:
                b.append("".join(row).replace("X", "."))
            build_ans.append(b)
        return build_ans

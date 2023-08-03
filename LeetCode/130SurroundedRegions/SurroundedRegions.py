class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        # DFS -> Time:O(n), Space:O(n^2)

        ROWS, COLS = len(board), len(board[0])

        def dfs(board,r,c):
            if (r < 0 or c < 0 or r >= ROWS or c >= COLS or board[r][c] != "O"):
                return
            board[r][c] = 'T'
            dfs(board, r-1, c)
            dfs(board, r+1, c)
            dfs(board, r, c-1)
            dfs(board, r, c+1)

        for i in range(ROWS):
            for j in range(COLS):
                if ((i == 0 or i == ROWS-1) or (j == 0 or j == COLS-1)) and board[i][j] == "O":
                    dfs(board, i, j)

        for i in range(ROWS):
            for j in range(COLS):
                if board[i][j] == "O":
                    board[i][j] = "X"
                if board[i][j] == "T":
                    board[i][j] = "O"

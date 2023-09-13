class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        # 2 passes -> Time:O(mn), Space:O(1) -> More elegant and slightly faster
        rows = len(board)
        cols = len(board[0])
        for r in range(rows):
            for c in range(cols):
                num_neighbours = 0
                for i in range(r-1, r+2):
                    for j in range(c-1, c+2):
                        if (i==r and j==c) or i<0 or j<0 or i>=rows or j>=cols:
                            continue
                        if board[i][j] in [1, 2]:
                            num_neighbours += 1
                if board[r][c] == 1 and (num_neighbours < 2 or num_neighbours > 3):
                    board[r][c] = 2
                elif board[r][c] == 0 and num_neighbours == 3:
                    board[r][c] = 3
        for r in range(rows):
            for c in range(cols):
                if board[r][c] == 2:
                    board[r][c] = 0
                elif board[r][c] == 3:
                    board[r][c] = 1


        # # 2 passes -> Time:O(mn), Space:O(1)
        # rows = len(board)
        # cols = len(board[0])
        # for r in range(rows):
        #     for c in range(cols):
        #         num_neighbours = 0
        #         for i in range(r-1, r+2):
        #             for j in range(c-1, c+2):
        #                 if (i==r and j==c) or i<0 or j<0 or i==rows or j==cols:
        #                     continue
        #                 if board[i][j] in [1, 3]:
        #                     num_neighbours += 1
        #         if board[r][c]:
        #             if num_neighbours in [2, 3]:
        #                 board[r][c] = 3
        #         elif num_neighbours == 3:
        #             board[r][c] = 2
        # for r in range(rows):
        #     for c in range(cols):
        #         if board[r][c] == 1:
        #             board[r][c] = 0
        #         elif board[r][c] in [2, 3]:
        #             board[r][c] = 1

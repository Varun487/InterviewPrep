class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # BOTH SOLUTIONS HAVE SAME TIME COMPLEXITY, BUT ARRAYS IS MUCH FASTER

        # Arrays -> Time:O(n^2), Space:O(n^2) n=SideOfBoard
        rows = [[0 for i in range(9)] for i in range(9)]
        cols = [[0 for i in range(9)] for i in range(9)]
        boxes = [[0 for i in range(9)] for i in range(9)]
        for i in range(9):
            for j in range(9):
                if board[i][j] != '.':
                    box_index = (i//3 + j//3) + (i//3 * 2)
                    num = int(board[i][j]) - 1
                    if rows[i][num] \
                    or cols[num][j] \
                    or boxes[box_index][num]:
                        return False
                    rows[i][num] = 1
                    cols[num][j] = 1
                    boxes[box_index][num] = 1
        return True


        # # Dictionary Set -> Time:O(n^2), Space:O(n^2) n=SideOfBoard
        # d = {}
        # for i in range(len(board)):
        #     d[f'R{i}'] = set()
        #     d[f'C{i}'] = set()
        #     d[f'B{i}'] = set()
        # for i in range(9):
        #     for j in range(9):
        #         box_index = (i//3 + j//3) + (i//3 * 2)
        #         if board[i][j] != '.':
        #             if board[i][j] in d[f'R{i}'] \
        #             or board[i][j] in d[f'C{j}'] \
        #             or board[i][j] in d[f'B{box_index}']:
        #                 return False
        #             d[f'R{i}'].add(board[i][j])
        #             d[f'C{j}'].add(board[i][j])
        #             d[f'B{box_index}'].add(board[i][j])
        # return True

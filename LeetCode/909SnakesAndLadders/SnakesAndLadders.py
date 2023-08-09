class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        # BFS -> Time:O(n^2), Space:O(n^2)
        n = len(board)
        board.reverse()
        def squareToPos(square):
            r = (square - 1) // n
            c = (square - 1) % n
            if r % 2:
                c = n - 1 - c
            return [r, c]
        q = []
        visited = set()
        q.append([1, 0])
        while q:
            square, moves = q.pop(0)
            for i in range(1, 7):
                next_square = square + i
                r, c = squareToPos(next_square)
                if board[r][c] != -1:
                    next_square = board[r][c]
                if next_square == n*n:
                    return moves + 1
                if next_square not in visited:
                    visited.add(next_square)
                    q.append([next_square, moves+1])
        return -1

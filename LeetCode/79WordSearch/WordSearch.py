class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        # DFS + Backtracking -> Time:O(n * m * 4^n), Space:O(m)
        visited = set()
        def backtrack(r, c, curr):
            if curr == len(word):
                return True
            if (
                r < 0
                or c < 0
                or r >= len(board)
                or c >= len(board[0])
                or word[curr] != board[r][c]
                or (r, c) in visited
            ):
                return False
            visited.add((r, c))
            res = (
                backtrack(r + 1, c, curr + 1)
                or backtrack(r - 1, c, curr + 1)
                or backtrack(r, c + 1, curr + 1)
                or backtrack(r, c - 1, curr + 1)
            )
            visited.remove((r, c))
            return res

        for r in range(len(board)):
            for c in range(len(board[0])):
                if backtrack(r, c, 0):
                    return True
        return False

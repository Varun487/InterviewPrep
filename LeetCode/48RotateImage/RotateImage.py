class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        # No extra memory -> Time:O(n^2) , Space:O(1)
        left, right = 0, len(matrix)-1
        while left < right:
            for i in range(right - left):
                top, bottom = left, right
                top_left = matrix[top][left + i]
                matrix[top][left + i] = matrix[bottom - i][left]
                matrix[bottom - i][left] = matrix[bottom][right - i]
                matrix[bottom][right - i] = matrix[top + i][right]
                matrix[top + i][right] = top_left
            left += 1
            right -= 1

        # # Allocating another matrix -> Time:O(n^2), Space:O(n^2)
        # n = len(matrix)
        # new_mat = [[0 for i in range(n)] for i in range(n)]
        # for i in range(n):
        #     for j in range(n):
        #         new_mat[j][n-i-1] = matrix[i][j]
        # for i in range(n):
        #     for j in range(n):
        #         matrix[i][j] = new_mat[i][j]

class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        # Constant space -> Time:O(nm), Space:O(1)
        first_row = False
        n = len(matrix)
        m = len(matrix[0])
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 0:
                    if i == 0:
                        first_row = True
                    else:
                        matrix[i][0] = 0
                    matrix[0][j] = 0
        for i in range(1, n):
            for j in range(1, m):
                if matrix[0][j] == 0 or matrix[i][0] == 0:
                    matrix[i][j] = 0
        if matrix[0][0] == 0:
            for i in range(n):
                matrix[i][0] = 0
        if first_row:
            for j in range(m):
                matrix[0][j] = 0

        # # rows and cols array -> Time:O(nm), Space:O(n+m)
        # rows = []
        # cols = []
        # n = len(matrix)
        # m = len(matrix[0])
        # for i in range(n):
        #     for j in range(m):
        #         if matrix[i][j] == 0:
        #             rows.append(i)
        #             cols.append(j)
        # for i in rows:
        #     for j in range(m):
        #         matrix[i][j] = 0
        # for j in cols:
        #     for i in range(n):
        #         matrix[i][j] = 0

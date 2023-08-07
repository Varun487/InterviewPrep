class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        # Binary Search -> Time:O(log(m)+log(n)), Space:O(1)
        start = 0
        end = len(matrix)-1
        mid = (start + end)//2
        while start <= end:
            mid = (start + end) // 2
            if target > matrix[mid][-1]:
                start = mid + 1
            elif target < matrix[mid][0]:
                end = mid - 1
            else:
                break
        if not start <= end:
            return False
        row = (start+end) // 2
        start = 0
        end = len(matrix[0])-1
        mid = (start + end)//2
        while start <= end:
            mid = (start + end) // 2
            if target > matrix[row][mid]:
                start = mid + 1
            elif target < matrix[row][mid]:
                end = mid - 1
            else:
                return True
        return False

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Binary Search -> Time:O(log(m)+log(n)), Space:O(1)
        int ROWS = matrix.size(), COLS = matrix[0].size();
        int start = 0, end = ROWS-1, mid;
        while (start <= end) {
            mid = (start + end) / 2;
            if (target > matrix[mid][COLS-1]) {
                start = mid + 1;
            }
            else if (target < matrix[mid][0]) {
                end = mid - 1;
            }
            else {
                break;
            }
        }
        if (start > end) {
            return false;
        }
        int row = (start + end) / 2;
        start = 0;
        end = COLS-1;
        while (start <= end) {
            mid = (start + end) / 2; 
            if (target > matrix[row][mid]) {
                start = mid + 1;
            }
            else if (target < matrix[row][mid]) {
                end = mid - 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};

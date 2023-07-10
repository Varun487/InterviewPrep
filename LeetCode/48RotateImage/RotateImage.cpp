class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // No extra memory -> Time:O(n^2) , Space:O(1)
        int temp, top, bottom, left = 0, right = matrix.size()-1;
        while (left < right) {
            for (int i  = 0; i < right - left; i++) {
                top = left;
                bottom = right;
                temp = matrix[top][left + i];
                matrix[top][left + i] = matrix[bottom - i][left];
                matrix[bottom - i][left] = matrix[bottom][right - i];
                matrix[bottom][right - i] = matrix[top + i][right];
                matrix[top + i][right] = temp;
            }
            left++;
            right--;
        }
    }
};

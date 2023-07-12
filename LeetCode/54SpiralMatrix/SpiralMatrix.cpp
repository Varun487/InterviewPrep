class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Single Pass -> Time:O(m*n), Space:O(1)
        vector<int> ans;
        int left = 0, right = matrix[0].size(), top = 0, bottom = matrix.size();
        while (left < right && top < bottom) {
            for (int i = left; i < right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top += 1;

            for (int i = top; i < bottom; i++) {
                ans.push_back(matrix[i][right-1]);
            }
            right -= 1;

            if (!(left < right && top < bottom)) {
                break;
            }

            for (int i = right-1; i > left-1; i--) {
                ans.push_back(matrix[bottom-1][i]);
            }
            bottom -= 1;

            for (int i = bottom-1; i > top-1; i--) {
                ans.push_back(matrix[i][left]);
            }
            left += 1;
        }
        return ans;
    }
};
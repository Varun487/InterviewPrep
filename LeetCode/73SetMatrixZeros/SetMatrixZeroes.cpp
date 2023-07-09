class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Constant memory -> Time:O(nm), Space:O(1)
        int n = matrix.size();
        int m = matrix[0].size();
        bool firstRow = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    if (i == 0) {
                        firstRow = true;
                    }
                    else {
                        matrix[i][0] = 0;
                    }
                }
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (matrix[0][0] == 0) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
        if (firstRow) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        // // 2 vectors -> Time: O(mn), Space:O(m+n)
        // int n = matrix.size();
        // int m = matrix[0].size();
        // vector<int> rows;
        // vector<int> cols;
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         if (matrix[i][j] == 0) {
        //             rows.push_back(i);
        //             cols.push_back(j);
        //         }
        //     }
        // }
        // for (int i = 0; i < rows.size(); i++) {
        //     for (int j = 0; j < m; j++) {
        //         matrix[rows[i]][j] = 0;
        //     }
        // }
        // for (int j = 0; j < cols.size(); j++) {
        //     for (int i = 0; i < n; i++) {
        //         matrix[i][cols[j]] = 0;
        //     }
        // }
    }
};

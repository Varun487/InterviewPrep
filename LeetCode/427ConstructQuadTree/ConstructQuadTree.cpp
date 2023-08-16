class Solution {
public:
    bool sameValues(vector<vector<int>>& grid) {
        int val = grid[0][0];
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                if (grid[i][j] != val) {
                    return false;
                }
            }
        }
        return true;
    }
    vector<vector<int>> sliceQuarter(vector<vector<int>>& grid, int i, int j, int k, int l) {
        vector<vector<int>> result;
        vector<int> temp;
        for (int a = i; a < j; a++) {
            temp.clear();
            for (int b = k; b < l; b++) {
                temp.push_back(grid[a][b]);
            }
            result.push_back(temp);
        }
        return result;
    }
    Node* construct(vector<vector<int>>& grid) {
        // Divide and Conquer -> Time:O(n*log(n)), Space:O(log(n))
        if (sameValues(grid)) {
            return new Node(bool(grid[0][0]), true);
        }
        Node* newNode = new Node();
        int n = grid.size();
        vector<vector<int>> quarterGrid = sliceQuarter(grid, 0, n/2, 0, n/2);
        newNode->topLeft = construct(quarterGrid);
        quarterGrid = sliceQuarter(grid, 0, n/2, n/2, n);
        newNode->topRight = construct(quarterGrid);
        quarterGrid = sliceQuarter(grid, n/2, n, 0, n/2);
        newNode->bottomLeft = construct(quarterGrid);
        quarterGrid = sliceQuarter(grid, n/2, n, n/2, n);
        newNode->bottomRight = construct(quarterGrid);
        return newNode;
    }
};

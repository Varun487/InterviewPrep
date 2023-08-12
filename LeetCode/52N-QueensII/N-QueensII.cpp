class Solution {
public:
    void backtrack(int &ans, set<int> &posDiag, set<int> &negDiag, set<int> &cols, int n, int r) {
        if (r == n) {
            ans++;
            return;
        }
        for (int c = 0; c < n; c++) {
            if (posDiag.find(r+c) == posDiag.end() && negDiag.find(r-c) == negDiag.end() && cols.find(c) == cols.end()) {
                cols.insert(c);
                posDiag.insert(r+c);
                negDiag.insert(r-c);
                backtrack(ans, posDiag, negDiag, cols, n, r+1);
                cols.erase(c);
                posDiag.erase(r+c);
                negDiag.erase(r-c);
            }
        }
    }
    int totalNQueens(int n) {
        // Backtracking -> Time:O(n^n), Space:O(n)
        set<int> posDiag;
        set<int> negDiag;
        set<int> cols;
        int ans = 0;
        backtrack(ans, posDiag, negDiag, cols, n, 0);
        return ans;
    }
};

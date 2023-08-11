class Solution {
public:
    void backtrack(int n, int k, vector<vector<int>> &ans, int start, vector<int> curr) {
        if (curr.size() == k) {
            ans.push_back(curr);
            return;
        }
        for (int i = start; i <= n; i++) {
            curr.push_back(i);
            backtrack(n, k, ans, i+1, curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        // Backtracking -> Time:O(n^k), Space:O(k)
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(n, k, ans, 1, curr);
        return ans;
    }
};

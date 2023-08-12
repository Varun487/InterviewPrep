class Solution {
public:
    void backtrack(vector<string> &ans, int n, int open_count, int close_count, string curr) {
        if (open_count == close_count && open_count == n) {
            ans.push_back(curr);
            return;
        }
        if (open_count < n) {
            backtrack(ans, n, open_count + 1, close_count, curr + "(");
        }
        if (close_count < open_count) {
            backtrack(ans, n, open_count, close_count + 1, curr + ")");
        }
    }
    vector<string> generateParenthesis(int n) {
        // Backtracking -> Time:O(n), Space:O(h)
        vector<string> ans;
        backtrack(ans, n, 0, 0, "");
        return ans;
    }
};

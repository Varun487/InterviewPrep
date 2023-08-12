class Solution {
public:
    void dfs(vector<vector<int>> &ans, vector<int>& candidates, int target, int i, vector<int> curr, int total) {
        if (total == target) {
            ans.push_back(curr);
            return;
        }
        if (i >= candidates.size() || total > target) {
            return;
        }
        curr.push_back(candidates[i]);
        dfs(ans, candidates, target, i, curr, total+candidates[i]);
        curr.pop_back();
        dfs(ans, candidates, target, i+1, curr, total);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // DFS + Backtracking -> Time:O(n), Space:O(h)
        vector<vector<int>> ans;
        vector<int> curr;
        dfs(ans, candidates, target, 0, curr, 0);
        return ans;
    }
};

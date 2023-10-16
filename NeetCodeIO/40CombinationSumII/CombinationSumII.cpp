class Solution {
public:
    set<vector<int>> ans;
    void dfs(vector<int>& candidates, int target, int i, vector<int> vals, int currSum) {
        currSum += candidates[i];
        if (currSum > target) return;
        vals.push_back(candidates[i]);
        if (currSum == target) {
            ans.insert(vals);
            return;
        }
        int prev = -1;
        for (int start = i+1; start < candidates.size(); start++) {
            if (candidates[start] != prev) {
                dfs(candidates, target, start, vals, currSum);
            }
            prev = candidates[start];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Sort + DFS -> Time:O(2^n), Space:O(n)
        vector<vector<int>> ansVec;
        vector<int> vals;
        sort(candidates.begin(), candidates.end());
        int currSum = 0;
        for (int i = 0; i < candidates.size(); i++) {
            dfs(candidates, target, i, vals, currSum);
        }
        for (auto i:ans) {
            ansVec.push_back(i);
        }
        return ansVec;
    }
};

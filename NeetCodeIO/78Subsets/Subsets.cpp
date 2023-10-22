class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, vector<int> sub, int ind) {
        if (ind >= nums.size()) {
            ans.push_back(sub);
            return;
        }
        dfs(nums, sub, ind+1);
        sub.push_back(nums[ind]);
        dfs(nums, sub, ind+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        // Backtracking -> Time:O(2^n), Space:O(n)
        vector<int> subSet;
        dfs(nums, subSet, 0);
        return ans;
    }
};

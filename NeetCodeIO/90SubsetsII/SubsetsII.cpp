class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, int i, vector<int> sub) {
        if (i >= nums.size()) {
            ans.push_back(sub);
            return;
        }
        sub.push_back(nums[i]);
        dfs(nums, i+1, sub);
        sub.erase(sub.end()-1);
        while (i+1 < nums.size() && nums[i] == nums[i+1]) {
            i++;
        }
        dfs(nums, i+1, sub);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Backtracking -> Time:O(2^n), Space:O(n)
        sort(nums.begin(), nums.end());
        vector<int> sub;
        dfs(nums, 0, sub);
        return ans;
    }
};

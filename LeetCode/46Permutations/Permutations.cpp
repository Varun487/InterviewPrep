class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // Backtracking -> Time:O(n*n!), Space:O(n!) n=nums.size()
        vector<vector<int>> ans, perms;
        if (nums.size() == 1) {
            ans.push_back(nums);
            return ans;
        }
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[0];
            nums.erase(nums.begin());
            perms = permute(nums);
            for (int j = 0; j < perms.size(); j++) {
                perms[j].push_back(n);
                ans.push_back(perms[j]);
            }
            nums.push_back(n);
        }
        return ans;
    }
};

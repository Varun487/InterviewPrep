class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, vector<int> perm, set<int> indexes) {
        if (perm.size() == nums.size()) {
            ans.push_back(perm);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (indexes.find(i) == indexes.end()) {
                perm.push_back(nums[i]);
                indexes.insert(i);
                dfs(nums, perm, indexes);
                perm.erase(perm.end()-1);
                indexes.erase(i);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // Backtracking -> Time:O(n*n!), Space:O(n!) n=nums.size()
        vector<int> perm;
        set<int> indexes;
        dfs(nums, perm, indexes);
        return ans;

    //     // Backtracking -> Time:O(n*n!), Space:O(n!) n=nums.size()
    //     vector<vector<int>> ans, perms;
    //     if (nums.size() == 1) {
    //         ans.push_back(nums);
    //         return ans;
    //     }
    //     for (int i = 0; i < nums.size(); i++) {
    //         int n = nums[0];
    //         nums.erase(nums.begin());
    //         perms = permute(nums);
    //         for (int j = 0; j < perms.size(); j++) {
    //             perms[j].push_back(n);
    //             ans.push_back(perms[j]);
    //         }
    //         nums.push_back(n);
    //     }
    //     return ans;
    }
};

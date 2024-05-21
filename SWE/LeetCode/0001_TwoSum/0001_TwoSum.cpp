class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Time: O(n), Space: O(n)
        map<int,int> m;
        vector<int> ans(2);
        for (int i = 0; i < nums.size(); i++) {
            int sub = target - nums[i];
            if (m.find(sub) != m.end()) {
                ans[0] = i;
                ans[1] = m[sub];
                return ans;
            }
            m[nums[i]] = i;
        }
        return ans;
    }
};

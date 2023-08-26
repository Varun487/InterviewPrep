class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 1D DP -> Time:O(n^2), Space:O(n)
        vector<int> lis(nums.size(), 1);
        for (int i = nums.size()-1; i > -1; i--) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] < nums[j]) {
                    lis[i] = max(lis[i], 1 + lis[j]);
                }
            }
        }
        int ans = lis[0];
        for (int i = 1; i < lis.size(); i++) {
            if (lis[i] > ans) {
                ans = lis[i];
            }
        }
        return ans;
    }
};

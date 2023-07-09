class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 2 pointers -> Time:O(n), Space:O(1)
        int l = 0, total = 0, ans = nums.size()+1;
        for (int r = 0; r < nums.size(); r++) {
            total += nums[r];
            while (total >= target) {
                ans = min(ans, r-l+1);
                total -= nums[l];
                l += 1;
            }
        }
        if (ans < nums.size()+1) {
            return ans;
        }
        return 0;
    }
};

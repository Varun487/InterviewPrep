class Solution {
public:
    bool canJump(vector<int>& nums) {
        // Greedy -> Time: O(n), Space: O(1)
        int end = nums.size() - 1;
        for (int i = end; i >= 0; i--) {
            if ((i+nums[i]) >= end) {
                end = i;
            }
        }
        return (end == 0);
    }
};
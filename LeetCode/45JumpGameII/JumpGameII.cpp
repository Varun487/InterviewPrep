class Solution {
public:
    int jump(vector<int>& nums) {
        // Greedy -> Time: O(n), Space: O(1)
        int longest_jump, l = 0, r = 0, jumps = 0;
        while (r < nums.size() - 1) {
            longest_jump = 0;
            for (int i = l; i < r + 1; i++) {
                if (longest_jump < i + nums[i]) {
                    longest_jump = i + nums[i];
                }
            }
            l = r + 1;
            r = longest_jump;
            jumps += 1;
        }
        return jumps;
    }
};

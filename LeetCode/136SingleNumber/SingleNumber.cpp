class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Bit Manipulation -> Time:O(n), Space:O(1)
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            ans ^= nums[i];
        }
        return ans;
    }
};

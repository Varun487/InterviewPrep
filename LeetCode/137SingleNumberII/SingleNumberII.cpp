class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Bit Manipulation -> Time:O(n), Space:O(1)
        int one = 0, two = 0;
        for (int i = 0; i < nums.size(); i++) {
            one ^= nums[i];
            one &= ~two;
            two ^= nums[i];
            two &= ~one;
        }
        return one;
    }
};

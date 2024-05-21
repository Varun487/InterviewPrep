class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Time: O(n), Space: O(n)
        set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) {
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};
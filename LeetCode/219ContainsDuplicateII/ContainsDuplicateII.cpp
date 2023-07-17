class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // 2 passes -> Time:O(n), Space:O(n)
        set<int> s;
        int l = 0, r = 0;
        while (r < nums.size()) {
            while (r - l <= k && r < nums.size()) {
                if (s.find(nums[r]) != s.end()) {
                    return true;
                }
                s.insert(nums[r]);
                r++;
            }
            if (r == nums.size()) {
                return false;
            }
            s.erase(nums[l]);
            l++;
        }
        return false;
    }
};

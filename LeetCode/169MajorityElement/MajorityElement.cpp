class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Boyer-Moore Method -> Time: O(n), Space: O(1)
        int res, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0 || res == nums[i]) {
                res = nums[i];
                count++;
            }
            else {
                count--;
            }
        }
        return res;

        // // HashMap method -> Time: O(n), Space: O(n)
        // unordered_map<int, int> m;
        // int n = nums.size();
        // int majority = n/2;
        // if (n%2) {
        //     majority++;
        // }
        // for (int i = 0; i < n; i++) {
        //     if (m.count(nums[i]) == 0) {
        //         m[nums[i]] = 0;
        //     }
        //     m[nums[i]] += 1;
        //     if (m[nums[i]] >= majority) {
        //         return nums[i];
        //     }
        // }
        // return 0;
    }
};

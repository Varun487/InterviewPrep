class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Partition method -> Time: O(n), Space: O(1)
        int k = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.count(nums[i]) == 0) {
                nums[k] = nums[i];
                m[nums[i]] = 1;
                k++;
            }
            else if (m[nums[i]] == 1) {
                nums[k] = nums[i];
                m[nums[i]] = 2;
                k++;
            }
        }
        return k;
    }
};
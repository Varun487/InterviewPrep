class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Partition method -> Time: O(n), Space: O(1)
        int k = 0;
        set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            if (s.count(nums[i]) == 0) {
                nums[k] = nums[i];
                s.insert(nums[i]);
                k++;
            }
        }
        return k;
    }
};
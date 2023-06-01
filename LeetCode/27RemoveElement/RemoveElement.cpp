class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // Partition method -> Time: O(n), Space: O(1)
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};
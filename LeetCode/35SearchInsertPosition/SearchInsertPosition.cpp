class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // Binary Search -> Time:O(logn), Space:O(1)
        int start = 0, end = nums.size()-1, mid = end/2;
        while (start < end) {
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
            mid = (end - start)/2 + start;
        }
        if (nums[start] < target) {
            return start + 1;
        }
        return start;
    }
};

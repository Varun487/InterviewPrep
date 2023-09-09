class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Binary Search -> Time:O(log(n)), Space:O(1)
        int mid, start = 0, end = nums.size()-1;
        while (start <= end) {
            mid = (start + end) / 2;
            if (target > nums[mid]) {
                start = mid + 1;
            }
            else if (target < nums[mid]) {
                end = mid - 1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
};

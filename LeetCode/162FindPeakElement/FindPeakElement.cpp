class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // Binary Search -> Time:O(log(n)), Space:O(1)
        int start = 0, end = nums.size()-1, mid;
        while (start <= end) {
            mid = (start + end) / 2;
            if (mid > 0 && nums[mid] < nums[mid - 1]) {
                end = mid - 1;
            }
            else if (mid < nums.size() - 1 && nums[mid] < nums[mid + 1]) {
                start = mid + 1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
};

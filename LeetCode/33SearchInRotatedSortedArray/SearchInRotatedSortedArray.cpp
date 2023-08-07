class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Binary Search -> Time:O(log(m)+log(n)), Space:O(1)
        int start = 0, end = nums.size()-1, mid;
        while(start <= end) {
            mid = (start+end)/2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] >= nums[start]) {
                if (target > nums[mid] || target < nums[start]) {
                    start = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }
            else {
                if (target > nums[end] || nums[mid] > target) {
                    end = mid - 1;
                }
                else {
                    start = mid + 1;
                }
            }
        }
        return -1;
    }
};

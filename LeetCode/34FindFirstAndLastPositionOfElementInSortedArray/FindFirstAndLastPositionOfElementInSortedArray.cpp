class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool check_left) {
        int start = 0, end = nums.size()-1, i = -1, mid;
        while (start <= end) {
            mid = (start + end) / 2;
            if (target > nums[mid]) {
                start = mid + 1;
            }
            else if (target < nums[mid]) {
                end = mid - 1;
            }
            else {
                i = mid;
                if (check_left) {
                    end = mid - 1;
                }
                else {
                    start = mid + 1;
                }
            }
        }
        return i;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        // Binary Search -> Time:O(log(n)), Space:O(1)
        vector<int> ans;
        ans.push_back(binarySearch(nums, target, true));
        ans.push_back(binarySearch(nums, target, false));
        return ans;
    }
};

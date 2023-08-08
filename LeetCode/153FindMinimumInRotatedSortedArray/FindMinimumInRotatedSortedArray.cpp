class Solution {
public:
    int findMin(vector<int>& nums) {
        // Binary Search -> Time:O(log(n)), Space:O(1)
        int start = 0, end = nums.size()-1, ans = nums[0], mid;
        while (start <= end) {
            if (nums[start] < nums[end]) {
                ans = min(ans, nums[start]);
                break;
            }
            mid = (start+end)/2;
            ans = min(ans, nums[mid]);
            if (nums[mid] >= nums[start]) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return ans;
    }
};

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Binary Search -> Time:O(log(m+n)), Space:O(1)
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int x = nums1.size(), y = nums2.size(), start = 0, end = x;
        int partitionX, partitionY, maxLeftX, maxLeftY, minRightX, minRightY;
        while (start <= end) {
            partitionX = (start + end) / 2;
            partitionY = ((x + y + 1) / 2) - partitionX;
            maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX-1];
            maxLeftY  = (partitionY == 0) ? INT_MIN : nums2[partitionY-1];
            minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];
            minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if ((x + y) % 2) {
                    return (double)max(maxLeftX, maxLeftY);
                }
                return (max(maxLeftX, maxLeftY)+min(minRightX, minRightY))/2.0;
            }
            else if (maxLeftX > minRightY) {
                end = partitionX - 1;
            }
            else {
                start = partitionX + 1;
            }
        }
        return 0.0;
    }
};

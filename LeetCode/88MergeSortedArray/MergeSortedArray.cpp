class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        // Without temp array -> Time: O(n), Space: O(1)
        while ( (m > 0) && (n > 0)) {
            if (nums1[m - 1] > nums2[n - 1]) {
                nums1[m+n-1] = nums1[m - 1];
                m--;
            }
            else {
                nums1[m+n-1] = nums2[n - 1];
                n--;
            }
        }
        while (n > 0) {
            nums1[m+n-1] = nums2[n - 1];
            n--;
        }

        // // With temp array -> Time: O(n), Space: O(n)
        // vector<int> nums3(m+n);
        // int i = 0;
        // int j = 0;
        // while ( (i < m) && (j < n)) {
        //     if (nums1[i] < nums2[j]) {
        //         nums3[i+j] = nums1[i];
        //         i++;
        //     }
        //     else {
        //         nums3[i+j] = nums2[j];
        //         j++;
        //     }
        // }
        // while (i < m) {
        //     nums3[i+n] = nums1[i];
        //     i++;
        // }
        // while (j < n) {
        //     nums3[j+m] = nums2[j];
        //     j++;
        // }
        // for (int k = 0; k < m+n; k++) {
        //     nums1[k] = nums3[k];
        // }
    }
};
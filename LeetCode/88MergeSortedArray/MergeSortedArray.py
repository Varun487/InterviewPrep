class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        # Time: O(n), Space: O(1)
        i, j = m-1, n-1
        while i > -1 and j > -1:
            if nums1[i] > nums2[j]:
                nums1[i+j+1] = nums1[i]
                i -= 1
            else:
                nums1[i+j+1] = nums2[j]
                j -= 1
        while i > -1:
            nums1[i+j+1] = nums1[i]
            i -= 1
        while j > -1:
            nums1[i+j+1] = nums2[j]
            j -= 1
        return nums1

        # # Without temp array -> Time: O(n), Space: O(1)
        # last = m + n - 1
        # while m > 0 and n > 0:
        #     if nums1[m - 1] > nums2[n - 1]:
        #         nums1[last] = nums1[m - 1]
        #         m -= 1
        #     else:
        #         nums1[last] = nums2[n - 1]
        #         n -= 1
        #     last -= 1
        # while n > 0:
        #     nums1[last] = nums2[n - 1]
        #     n -= 1
        #     last -= 1


        # # With temp array -> Time: O(n), Space: O(n)
        # nums3 = []
        # i = 0
        # j = 0
        # while i < m and j < n:
        #     if nums1[i] < nums2[j]:
        #         nums3.append(nums1[i])
        #         i += 1
        #     else:
        #         nums3.append(nums2[j])
        #         j += 1
        # while i < m:
        #     nums3.append(nums1[i])
        #     i += 1
        # while j < n:
        #     nums3.append(nums2[j])
        #     j += 1
        # for i in range(len(nums3)):
        #     nums1[i] = nums3[i]

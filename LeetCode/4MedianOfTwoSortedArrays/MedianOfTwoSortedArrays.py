class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # Binary Search -> Time:O(log(m+n)), Space:O(1)
        if len(nums1) > len(nums2):
            return self.findMedianSortedArrays(nums2, nums1)
        x = len(nums1)
        y = len(nums2)
        start = 0
        end = x
        while (start <= end):
            partitionX = (start+end)//2
            partitionY = (x+y+1)//2 - partitionX
            maxLeftX = float('-inf') if partitionX == 0 else nums1[partitionX-1]
            minRightX = float('inf') if partitionX == x else nums1[partitionX]
            maxLeftY = float('-inf') if partitionY == 0 else nums2[partitionY-1]
            minRightY = float('inf') if partitionY == y else nums2[partitionY]
            if maxLeftX <= minRightY and maxLeftY <= minRightX:
                if (x+y)%2:
                    return max(maxLeftX, maxLeftY)
                return (max(maxLeftX, maxLeftY)+min(minRightX, minRightY)) / 2
            elif maxLeftX > minRightY:
                end  = partitionX - 1
            else:
                start = partitionX + 1
        return -1
        
        # # Brute Force -> Time:O(m+n), Space:O(m+n)
        # combined = []
        # i, j = 0, 0
        # while i < len(nums1) and j < len(nums2):
        #     if nums1[i] <= nums2[j]:
        #         combined.append(nums1[i])
        #         i += 1
        #     else:
        #         combined.append(nums2[j])
        #         j += 1
        # while i < len(nums1):
        #     combined.append(nums1[i])
        #     i += 1
        # while j < len(nums2):
        #     combined.append(nums2[j])
        #     j += 1
        # mid = len(combined)//2
        # if len(combined)%2:
        #     return float(combined[mid])
        # else:
        #     return (combined[mid] + combined[mid-1])/2

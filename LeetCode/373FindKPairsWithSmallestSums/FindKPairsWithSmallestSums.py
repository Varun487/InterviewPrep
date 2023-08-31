import heapq

class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        # Heap -> Time:O(k*log(n+m)), Space:O(n+m)
        visited = set()
        pairs = []
        ans = []
        heapq.heappush(pairs, (nums1[0]+nums2[0], 0, 0))
        visited.add((0, 0))
        count = 0
        while pairs and count < k:
            s, i, j = heapq.heappop(pairs)
            ans.append([nums1[i], nums2[j]])
            visited.add((i, j))
            if (i, j+1) not in visited and i < len(nums1) and j+1 < len(nums2):
                heapq.heappush(pairs, (nums1[i]+nums2[j+1], i, j+1))
                visited.add((i, j+1))
            if (i+1, j) not in visited and i+1 < len(nums1) and j < len(nums2):
                heapq.heappush(pairs, (nums1[i+1]+nums2[j], i+1, j))
                visited.add((i+1, j))
            count += 1
        return ans

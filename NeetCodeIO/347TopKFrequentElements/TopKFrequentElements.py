class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # Bucket Sort -> Time:O(n), Space:O(n)
        count = {}
        freq = [[] for i in range(len(nums)+1)]
        ans = []
        for i in nums:
            if i not in count:
                count[i] = 0
            count[i] += 1
        for n,c in count.items():
            freq[c].append(n)
        for i in range(len(nums), 0, -1):
            for n in freq[i]:
                ans.append(n)
                if len(ans) == k:
                    return ans
        return ans

class Solution:
    def hIndex(self, citations: List[int]) -> int:
        # Merge Sort, then find h index -> Time: O(nlogn), Space: O(1)
        citations.sort()
        n = len(citations)
        i = 1
        while i <= n:
            if citations[n-i] < i:
                break
            i += 1
        return i-1

        # # Brute force -> Time: O(n^2), Space: O(1)
        # for i in range(len(citations), -1, -1):
        #     num_papers = 0
        #     for j in range(0, len(citations)):
        #         if citations[j] >= i:
        #             num_papers += 1
        #     if num_papers >= i:
        #         return i
        # return 0

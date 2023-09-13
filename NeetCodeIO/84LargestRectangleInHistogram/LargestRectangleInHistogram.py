class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        # Stack -> Time:O(n), Space:O(1)
        ans = 0
        stack = []
        for i, h in enumerate(heights):
            start = i
            while stack and stack[-1][1] > h:
                idx, ht = stack.pop()
                ans = max(ans, ht * (i - idx))
                start = idx
            stack.append((start, h))
        for i, h in stack:
            ans = max(ans, h*(len(heights)-i))
        return ans

        # # Brute Force -> Time:O(n^2), Space:O(1) -> Time Limit Exceeded
        # ans = 0
        # for i in range(len(heights)):
        #     m = heights[i]
        #     if m > ans:
        #         ans = m
        #     for j in range(i+1, len(heights)):
        #         if heights[j] < m:
        #             m = heights[j]
        #         # print(i, j, m)
        #         if m * (j-i+1) > ans:
        #             ans = m * (j-i+1)
        # return ans

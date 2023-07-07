class Solution:
    def maxArea(self, height: List[int]) -> int:
        # 2 pointers -> Time:O(n), Space:O(1)
        l,r = 0, len(height)-1
        ans = 0
        while l < r:
            water = (r-l) * min(height[l], height[r])
            if water > ans:
                ans = water
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return ans

        # # Brute force -> Time:O(n^2), Space:O(1)
        # ans = 0
        # for l in range(len(height)):
        #     for r in range(l+1, len(height)):
        #         water = min(height[l],height[r]) * (r-l)
        #         if water > ans:
        #             ans = water
        # return ans

class Solution:
    def trap(self, height: List[int]) -> int:
        # Constant space -> Time:O(n), Space:O(1)
        if len(height) < 3:
            return 0
        ans = 0
        L = 0
        R = len(height) - 1
        maxL = height[L]
        maxR = height[R]
        while L < R:
            if maxL <= maxR:
                L += 1
                maxL = max(maxL, height[L])
                ans += maxL - height[L]
            else:
                R -= 1
                maxR = max(maxR, height[R])
                ans += maxR - height[R]
        return ans

        # # Store L and R -> Time:O(n), Space:O(n)
        # maxL = []
        # maxR = []
        # minLR = [0 for i in range(len(height))]
        # ans = 0
        # maxL_num = 0
        # maxR_num = 0
        # for i in range(len(height)):
        #     maxL.append(maxL_num)
        #     maxR.append(maxR_num)
        #     if height[i] > maxL_num:
        #         maxL_num = height[i]
        #     if height[-i-1] > maxR_num:
        #         maxR_num = height[-i-1]
        # for i in range(len(height)):
        #     minLR[i] = min(maxL[i], maxR[-i-1])
        # for i in range(len(height)):
        #     ans += minLR[i] - height[i] if minLR[i] - height[i] > 0 else 0
        # return ans

        # # Naive -> Time:O(n^2), Space:O(1)
        # if len(height) < 3:
        #     return 0
        # ans = 0
        # for i in range(1, len(height)):
        #     L = max(height[0:i])
        #     R = max(height[i:len(height)])
        #     trapped_water = min(L, R) - height[i]
        #     ans += trapped_water if trapped_water > 0 else 0
        # return ans

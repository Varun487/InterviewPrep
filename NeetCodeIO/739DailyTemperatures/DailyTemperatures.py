class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        # Stack -> Time:O(n), Space:O(n)
        stack = []
        ans  = [0] * len(temperatures)
        for i, t in enumerate(temperatures):
            while stack and t > stack[-1][0]:
                temp, ind = stack.pop()
                ans[ind] = i - ind
            stack.append([t, i])
        return ans

        # # Time:O(n^2), Space:O(1) -> Time Limit Exceeded
        # ans = [0 for i in range(len(temperatures))]
        # for i in range(len(temperatures)):
        #     for j in range(i+1, len(temperatures)):
        #         if temperatures[j] > temperatures[i]:
        #             ans[i] = j-i
        #             break
        # return ans

class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        # Single Pass -> Time:O(nlogn), Space:O(1)
        points.sort(key = lambda i: i[1])
        ans = 1
        end = points[0][1]
        for i in range(len(points)):
            if points[i][0] > end:
                ans += 1
                end = points[i][1]
        return ans

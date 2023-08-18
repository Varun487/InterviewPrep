class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        # Compute slope -> Time:O(n^2), Space:O(n)
        max_p = 1
        for i in range(len(points)):
            d = {}
            curr_p = points[i]
            for j in range(i+1, len(points)):
                next_p = points[j]
                num = (curr_p[1] - next_p[1])
                den = (curr_p[0] - next_p[0])
                if den == 0:
                    slope = float('inf')
                else:
                    slope = num / den
                if slope not in d:
                    d[slope] = set()
                d[slope].add(tuple(points[i]))
                d[slope].add(tuple(points[j]))
                if len(d[slope]) > max_p:
                    max_p = len(d[slope])
        return max_p

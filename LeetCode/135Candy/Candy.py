class Solution:
    def candy(self, ratings: List[int]) -> int:
        # Time:O(n), Space:O(n)
        n = len(ratings)
        l2r = [1 for i in range(n)]
        r2l = [1 for i in range(n)]
        candies = 0
        for i in range(n):
            if i > 0 and ratings[i] > ratings[i-1]:
                l2r[i] = l2r[i-1] + 1
        for i in range(n-2, -1, -1):
            if i > -1 and ratings[i] > ratings[i+1]:
                r2l[i] = r2l[i+1] + 1
        for i in range(n):
            candies += max(l2r[i], r2l[i])
        return candies

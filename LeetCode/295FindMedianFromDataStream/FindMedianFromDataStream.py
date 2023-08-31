import heapq

class MedianFinder:

    def __init__(self):
        self.small, self.large = [], []
        # self.median = 0
        # self.nums = []

    def addNum(self, num: int) -> None:
        # 2 heaps -> Time:O(log(n)), Space:O(n)
        heapq.heappush(self.small, -1*num)
        if (self.small and self.large and (-1*self.small[0]) > self.large[0]) \
            or len(self.small) > len(self.large) + 1:
            val = -1* heapq.heappop(self.small)
            heapq.heappush(self.large, val)
        if len(self.large) > len(self.small) + 1:
            val = heapq.heappop(self.large)
            heapq.heappush(self.small, -1*val)
        
        # # Insert to sorted array -> Time:O(n), Space:O(n) -> Time Limit Exceeded
        # if not self.nums or num >= self.nums[-1]:
        #     self.nums.append(num)
        # else:
        #     for i in range(len(self.nums)):
        #         if self.nums[i] > num:
        #             self.nums.insert(i, num)
        #             break

    def findMedian(self) -> float:
        # Find median -> Time:O(1), Space:O(1)
        if len(self.small) > len(self.large):
            return -1*self.small[0]
        elif len(self.large) > len(self.small):
            return self.large[0]
        else:
            return (-1*self.small[0] + self.large[0]) / 2
        
        # # Find median -> Time:O(1), Space:O(1) -> Time Limit Exceeded
        # n = len(self.nums)
        # if n%2:
        #     self.median = self.nums[n//2]
        # else:
        #     self.median = (self.nums[n//2] + self.nums[n//2 - 1]) / 2
        # return self.median

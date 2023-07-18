class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        # Sort + Merge -> Time:O(nlogn), Space:O(1)
        intervals.sort(key = lambda i: i[0])
        i = 0
        while i < len(intervals) -  1:
            if intervals[i][1] >= intervals[i+1][0]:
                if intervals[i][1] < intervals[i+1][1]:
                    intervals[i][1] = intervals[i+1][1]
                if intervals[i][0] > intervals[i+1][0]:
                    intervals[i][0] = intervals[i+1][0]
                intervals.pop(i+1)
            else:
                i += 1
        return intervals

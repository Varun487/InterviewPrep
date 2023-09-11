class TimeMap:

    def __init__(self):
        self.d = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        # Dict of Dict -> Time:O(1), Space:O(1)
        if key not in self.d:
            self.d[key] = []
        self.d[key].append([timestamp, value])
        
    def get(self, key: str, timestamp: int) -> str:
        # Binary Search -> Time:O(log(n)), Space:O(1) n:len(values)
        if key not in self.d:
            return ""
        ans = ""
        values = self.d[key]
        start, end = 0, len(values) - 1
        while start <= end:
            mid = (start+end) // 2
            if values[mid][0] == timestamp:
                return values[mid][1]
            elif values[mid][0] < timestamp:
                ans = values[mid][1]
                start = mid + 1
            else:
                end = mid - 1
        return ans

# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)

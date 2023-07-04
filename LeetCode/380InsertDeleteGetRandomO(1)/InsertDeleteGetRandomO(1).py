class RandomizedSet:

    def __init__(self):
        self.nums_map = {}
        self.nums_array = []        

    # Time:O(1), Space:O(n)
    def insert(self, val: int) -> bool:
        if val not in self.nums_map:
            self.nums_map[val] = len(self.nums_array)
            self.nums_array.append(val)
            return True
        return False

    # Time:O(1), Space:O(n)
    def remove(self, val: int) -> bool:
        if val in self.nums_map:
            self.nums_array[self.nums_map[val]] = self.nums_array[len(self.nums_array) - 1]
            self.nums_map[self.nums_array[len(self.nums_array) - 1]] = self.nums_map[val]
            del self.nums_map[val]
            self.nums_array.pop()
            return True
        return False        

    # Time:O(1), Space:O(1)
    def getRandom(self) -> int:
        return random.choice(self.nums_array)

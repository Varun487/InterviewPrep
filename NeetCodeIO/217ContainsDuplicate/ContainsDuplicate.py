class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        # Single Pass -> Time:O(n), Space:(n)
        s = set()
        for i in nums:
            if i in s:
                return True
            s.add(i)
        return False

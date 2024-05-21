class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        # Time: O(n), Space: O(n)
        s = set()
        for i in nums:
            if i in s:
                return True
            s.add(i)
        return False

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        # Bit Manipulation -> Time:O(n), Space:O(1)
        one = 0
        two = 0
        for i in nums:
            one ^= i
            one &= ~two
            two ^= i
            two &= ~one
        return one

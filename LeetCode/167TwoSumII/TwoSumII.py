class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        # 2 pointers -> Time:O(n), Space:O(1)
        l = 0
        r = len(numbers) - 1
        while numbers[l] + numbers[r] != target:
            if target - numbers[r] > numbers[l]:
                l += 1
            else:
                r -= 1
        return [l+1, r+1]

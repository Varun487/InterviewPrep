class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        # Single Pass -> Time:O(n), Space:O(n)
        s, carry = 0, 0
        for i in range(len(digits)-1, -1, -1):
            s = digits[i]
            if i == len(digits)-1:
                s += 1
            s += carry
            carry = s//10
            digits[i] = s%10
        if carry:
            digits.insert(0,1)
        return digits

        # Pythonic -> Time:O(n), Space:O(n)
        return [int(i) for i in str(int("".join(map(lambda x: str(x), digits)))+1)]

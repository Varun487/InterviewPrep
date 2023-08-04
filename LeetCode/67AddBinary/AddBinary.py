class Solution:
    def addBinary(self, a: str, b: str) -> str:
        # Bit -> Time:O(n), Space:O(n)
        smaller = a
        bigger = b
        ans = ""
        if len(a) > len(b):
            bigger = a
            smaller = b
        carry = 0
        s = 0
        for i in range(1, len(smaller)+1):
            s = int(smaller[-i]) + int(bigger[-i]) + carry
            if s > 1:
                carry = 1
                s -= 2
            else:
                carry = 0
            ans = str(s) + ans
        i = len(smaller)
        for i in range(len(smaller), len(bigger)):
            s = int(bigger[-i-1]) + carry
            if s > 1:
                carry = 1
                s -= 2
            else:
                carry = 0
            ans = str(s) + ans
        if carry:
            ans = '1' + ans
        return ans

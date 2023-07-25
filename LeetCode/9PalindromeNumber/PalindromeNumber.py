class Solution:
    def isPalindrome(self, x: int) -> bool:
        # Reverse Number -> Time:O(n), Space:O(1)
        if x < 0:
            return False
        def reverse_num(x):
            num = 0
            while x:
                digit = x%10
                num = num*10 + digit
                x //= 10
            return num
        return x == reverse_num(x)

        # # Pythonic: Time:O(n), Space:O(n)
        # return str(x)[::-1] == str(x)

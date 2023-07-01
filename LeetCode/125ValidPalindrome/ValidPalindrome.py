class Solution:
    def isPalindrome(self, s: str) -> bool:
        # Two pointers -> Time:O(n), Space:O(1)
        i = 0
        n = len(s)
        j = n-1
        while i < j:
            while i < j and not s[i].isalnum():
                i += 1
            while i < j and not s[j].isalnum():
                j -= 1
            if s[i].lower() != s[j].lower():
                return False
            i += 1
            j -= 1
        return True

        # Preprocessing for pythonic and naive solutions
        # new_s = ""
        # for i in s:
        #     if i.isalnum():
        #         new_s += i.lower()
        
        # # Pythonic -> Time:O(n), Space:O(n)
        # return new_s == new_s[::-1]
        
        # # Naive -> Time:O(n), Space:O(n)
        # palin = True
        # i = 0
        # n = len(new_s)
        # while i < n//2:
        #     if new_s[i] != new_s[n-1-i]:
        #         palin = False
        #         break
        #     i += 1
        # return palin

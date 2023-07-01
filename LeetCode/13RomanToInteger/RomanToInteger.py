class Solution:
    def romanToInt(self, s: str) -> int:
        # Linear solution -> Time:O(n), Space:O(1)
        roman_to_int_dict = {
            'I':1,
            'V':5,
            'X':10,
            'L':50,
            'C':100,
            'D':500,
            'M':1000,
        }
        i = 0
        int_sum = 0
        while i < len(s) - 1:
            if roman_to_int_dict[s[i]] < roman_to_int_dict[s[i+1]]:
                int_sum -= roman_to_int_dict[s[i]]
            else:
                int_sum += roman_to_int_dict[s[i]]
            i += 1
        int_sum += roman_to_int_dict[s[i]]
        return int_sum

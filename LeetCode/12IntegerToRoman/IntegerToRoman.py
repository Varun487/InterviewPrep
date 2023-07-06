class Solution:
    def intToRoman(self, num: int) -> str:
        # Single pass -> Time:O(n), Space:O(1)
        symbol_value = [
            [1000, 'M'],
            [900, 'CM'],
            [500, 'D'],
            [400, 'CD'],
            [100, 'C'],
            [90, 'XC'],
            [50, 'L'],
            [40, 'XL'],
            [10, 'X'],
            [9, 'IX'],
            [5, 'V'],
            [4, 'IV'],
            [1, 'I'],
        ]
        ans = ""
        for val, sym in symbol_value:
            ans += sym*(num//val)
            num %= val
        return ans

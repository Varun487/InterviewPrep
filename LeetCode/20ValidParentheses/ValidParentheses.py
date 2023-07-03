class Solution:
    def isValid(self, s: str) -> bool:
        # Stack -> Time:O(n), Space:O(1)
        stack  = []
        bracket_map = {
            ']':'[',
            ')':'(',
            '}':'{',
        }
        for i in s:
            if i not in bracket_map:
                stack.append(i)
            elif stack != [] and stack[-1] == bracket_map[i]:
                stack.pop()
            else:
                return False
        if stack == []:
            return True
        return False

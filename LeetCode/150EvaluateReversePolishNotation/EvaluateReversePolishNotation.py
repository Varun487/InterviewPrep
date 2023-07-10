class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        # Stack -> Time:O(n), Space:O(n)
        s = []
        for i in tokens:
            if i == "+":
                b = s.pop()
                a = s.pop()
                s.append(a+b)
            elif i == "-":
                b = s.pop()
                a = s.pop()
                s.append(a-b)
            elif i == "/":
                b = s.pop()
                a = s.pop()
                if a/b < 0:
                    s.append(math.ceil(a/b))
                else:
                    s.append(math.floor(a/b))
            elif i == "*":
                b = s.pop()
                a = s.pop()
                s.append(a*b)
            else:
                s.append(int(i))
        return s[0]

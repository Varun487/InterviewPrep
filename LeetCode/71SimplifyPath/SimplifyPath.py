class Solution:
    def simplifyPath(self, path: str) -> str:
        # Stack -> Time:O(n), Space:O(n)
        s = []
        curr = ""
        for i in path + "/":
            if i == '/':
                if curr == "..":
                    if s != []:
                        s.pop()
                elif curr != "" and curr != '.':
                    s.append(curr)
                curr = ""
            else:
                curr += i
        return '/' + '/'.join(s)

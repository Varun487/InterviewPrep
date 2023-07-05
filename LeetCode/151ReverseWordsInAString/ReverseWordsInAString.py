class Solution:
    def reverseWords(self, s: str) -> str:
        # Single pass -> Time:O(n), Space:O(n) n=len(s)
        ans = ''
        n = len(s)
        i = 0
        while i < n:
            while i < n and s[i] == ' ':
                i += 1
            if i >= n:
                break
            j = i+1
            while j < n and s[j] != ' ':
                j += 1
            if ans == '':
                ans = s[i:j]
            else:
                ans = s[i:j] + ' ' + ans
            i = j + 1
        return ans

        # # Time:O(n+m), Space:O(m) n=len(s),m=len(words)
        # string = ''
        # n = len(s)
        # words = []
        # for i in range(n):
        #     if s[i] == ' ':
        #         if string:
        #             words.append(string)
        #         string = ''
        #     else:
        #         string += s[i]
        # if string:
        #     words.append(string)
        # m = len(words)
        # for i in range(m//2):
        #     words[i], words[m-i-1] = words[m-i-1], words[i]
        # ans = ''
        # for i in range(m):
        #     ans += words[i]
        #     if i != m-1:
        #         ans += ' '
        # return ans

        # Pythonic -> Time:O(n+m), Space:O(m) n=number of words
        # return " ".join(s.split()[::-1])

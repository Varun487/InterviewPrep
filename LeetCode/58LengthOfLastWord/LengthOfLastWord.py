class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        # More elegant solution -> Time:O(n), Space:O(1)
        ans, prev_space = 0, False
        for c in s:
            if c == ' ':
                prev_space = True
            elif prev_space:
                ans = 1
                prev_space = False
            else:
                ans += 1
        return ans

        # # Pythonic Solution
        # return len(s.split()[-1])

        # # Naive solution -> Time:O(n), Space:O(1)
        # last_word_length = 0
        # current_word_length = 0 
        # for i in s:
        #     if i != ' ':
        #         current_word_length += 1
        #     elif current_word_length != 0:
        #         last_word_length = current_word_length
        #         current_word_length = 0
        #     else:
        #         current_word_length = 0
        # if current_word_length != 0:
        #     return current_word_length
        # return last_word_length

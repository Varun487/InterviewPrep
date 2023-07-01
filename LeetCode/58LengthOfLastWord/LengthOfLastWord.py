class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        # Pythonic Solution
        return len(s.split()[-1])

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

class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        # Single Pass -> Time:O(n), Space:O(n)
        ans = []
        line_length = 0
        line_string = ""
        for i in range(len(words)):
            if len(line_string) + len(words[i]) > maxWidth:
                ans.append(line_string[:len(line_string)-1])
                line_string = words[i] + " "
            else:
                line_string += words[i] + " "
        if line_string:
            ans.append(line_string[:len(line_string)-1])
        for i in range(len(ans)):
            if i == len(ans)-1 or (len(ans[i]) < maxWidth and len(ans[i].split()) == 1):
                ans[i] += ' '*(maxWidth - len(ans[i]))
            elif len(ans[i]) < maxWidth:
                w = ans[i].split()
                num_words = len(w)
                num_slots = num_words - 1
                words_total_len = len(''.join(w))
                num_spaces = maxWidth - words_total_len
                spaces = ' '*(num_spaces//num_slots)
                extra_spaces = num_spaces%num_slots
                string = ''
                for word in range(num_words):
                    string += w[word]
                    if word != num_words-1:
                        string += spaces
                        if extra_spaces:
                            string += ' '
                            extra_spaces -= 1
                ans[i] = string
        return ans

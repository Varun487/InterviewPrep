class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        # Double pass -> Time:O(n^2), Space:O(n)
        words_frequency = {}

        for word in words:
            if word not in words_frequency:
                words_frequency[word] = 0
            words_frequency[word] += 1

        total_words = len(words)
        word_length = len(words[0])
        ans = []

        for i in range(len(s) - total_words*word_length + 1):
            seen_words = {}
            for j in range(total_words):
                word_index = i + j*word_length
                sub_str = s[word_index:word_index+word_length]
                if sub_str not in words_frequency:
                    break
                if sub_str not in seen_words:
                    seen_words[sub_str] = 0
                seen_words[sub_str] += 1
                if seen_words[sub_str] > words_frequency[sub_str]:
                    break
                if j + 1 == total_words:
                    ans.append(i)
        
        return ans

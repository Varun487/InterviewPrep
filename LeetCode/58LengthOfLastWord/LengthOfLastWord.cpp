class Solution {
public:
    int lengthOfLastWord(string s) {
        // Naive solution -> Time:O(n), Space:O(1)
        int last_word_length = 0;
        int current_word_length = 0;
        for(int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                current_word_length += 1;
            }
            else if (current_word_length != 0) {
                last_word_length = current_word_length;
                current_word_length = 0;
            }
            else {
                current_word_length = 0;
            }
        }
        if (current_word_length != 0) {
            return current_word_length;
        }
        return last_word_length;
    }
};

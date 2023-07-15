class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // Double pass -> Time:O(n^2), Space:O(n)
        unordered_map<string, int> words_frequency;
        int word_length = words[0].size();
        int num_words = words.size();
        int string_length = s.size();
        vector<int> ans;
        for (int i = 0; i < words.size(); i++) {
            words_frequency[words[i]]++;
        }
        for (int i = 0; i <= string_length - (num_words*word_length); i++) {
            unordered_map<string, int> seen_words;
            for (int j = 0; j < num_words; j++) {
                int word_index = i + j*word_length;
                string word = s.substr(word_index, word_length);
                if (words_frequency.find(word) == words_frequency.end()) {
                    break;
                }
                seen_words[word]++;
                if (seen_words[word] > words_frequency[word]) {
                    break;
                }
                if (j+1 == num_words) {
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};

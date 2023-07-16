class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Hashmap -> Time:O(mn), Space:O(mn)
        map<vector<int>, vector<string> > anagram_groups;
        string word;
        for (int i = 0; i < strs.size(); i++) {
            word = strs[i];
            vector<int> count(26, 0);
            for (int j = 0; j < word.size(); j++) {
                count[word[j] - 'a']++;
            }
            anagram_groups[count].push_back(word);
        }
        vector<vector<string>> ans;
        for (auto i: anagram_groups) {
            ans.push_back(i.second);
        }
        return ans;
    }
};

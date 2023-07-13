class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // 2 hashmaps optimized -> Time:O(n+m), Space:O(n+m)
        map<char, string> p_s;
        map<string, char> s_p;
        vector<string> s_words;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            s_words.push_back(word);
        }
        if (s_words.size() != pattern.size()) {
            return false;
        }
        for (int i = 0; i < pattern.size(); i++) {
            if (p_s.find(pattern[i]) != p_s.end() && p_s[pattern[i]] != s_words[i]) {
                return false;
            }
            if (s_p.find(s_words[i]) != s_p.end() && s_p[s_words[i]] != pattern[i]) {
                return false;
            }            
            p_s[pattern[i]] = s_words[i];
            s_p[s_words[i]] = pattern[i];
        }
        return true;


        // // 2 hashmaps -> Time:O(n+m), Space:O(n+m)
        // map<char, string> p_s;
        // map<string, char> s_p;
        // vector<string> s_words;
        // stringstream ss(s);
        // string word;
        // while (ss >> word) {
        //     s_words.push_back(word);
        // }
        // if (s_words.size() != pattern.size()) {
        //     return false;
        // }
        // for (int i = 0; i < pattern.size(); i++) {
        //     if (p_s.find(pattern[i]) == p_s.end() && s_p.find(s_words[i]) == s_p.end()) {
        //         p_s[pattern[i]] = s_words[i];
        //         s_p[s_words[i]] = pattern[i];
        //     }
        //     else if (p_s.find(pattern[i]) == p_s.end() && s_p.find(s_words[i]) != s_p.end()) {
        //         return false;
        //     }
        //     else if (p_s.find(pattern[i]) != p_s.end() && s_p.find(s_words[i]) == s_p.end()) {
        //         return false;
        //     }
        //     else if (p_s[pattern[i]] != s_words[i] || s_p[s_words[i]] != pattern[i]) {
        //         return false;
        //     }
        // }
        // return true;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        // Sorting -> Time:O(slog(s)+tlog(t)), Space:O(1) ~ optimized, O(n) ~ worst case
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;

        // 2 dictionaries -> Time:O(s+t), Space:O(s+t) [worst case]
        std::map<char, int> s_map;
        std::map<char, int> t_map;
        for (int i = 0; i < s.size(); i++) {
            if (s_map.find(s[i]) == s_map.end()) {
                s_map[s[i]] = 0;
            }
            s_map[s[i]] += 1;
        }
        for (int i = 0; i < t.size(); i++) {
            if (t_map.find(t[i]) == t_map.end()) {
                t_map[t[i]] = 0;
            }
            t_map[t[i]] += 1;
        }
        return s_map == t_map;
    }
};

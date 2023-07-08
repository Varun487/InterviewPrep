class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // 2 dictionaries -> Time:O(n), Space:O(n)
        map<char, char> s_map;
        map<char, char> t_map;
        for (int i = 0; i < s.size(); i++) {
            if (s_map.count(s[i]) == 0 && t_map.count(t[i]) == 0) {
                s_map[s[i]] = t[i];
                t_map[t[i]] = s[i];
            }
            else if (s_map.count(s[i]) == 0 || t_map.count(t[i]) == 0) {
                return false;
            }
            else if (s_map[s[i]] != t[i] || t_map[t[i]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};

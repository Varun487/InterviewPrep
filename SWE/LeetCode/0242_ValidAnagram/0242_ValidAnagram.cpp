class Solution {
public:
    bool isAnagram(string s, string t) {
        // Time: O(n + m), Space: O(n + m)
        unordered_map<char,int> s_map, t_map;
        for (int i = 0; i < s.size(); i++) {
            s_map[s[i]]++;
        }
        for (int i = 0; i < t.size(); i++) {
            t_map[t[i]]++;
        }
        return s_map == t_map;
    }
};
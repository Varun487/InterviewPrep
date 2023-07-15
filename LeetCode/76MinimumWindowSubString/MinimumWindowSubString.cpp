class Solution {
public:
    string minWindow(string s, string t) {
        // Single Pass -> Time:O(n), Space:O(n)
        unordered_map<char, int> tmap;
        for (int i = 0; i < t.size(); i++) {
            tmap[t[i]]++;
        }
        int l = 0, have = 0, need = tmap.size();
        vector<int> res {-1, -1};
        int res_len = s.size()+1;
        char c;
        unordered_map<char, int> sub_str_map;
        for (int r = 0; r < s.size(); r++) {
            c = s[r];
            sub_str_map[c]++;
            if (tmap.find(c) != tmap.end() && tmap[c] == sub_str_map[c]) {
                have++;
            }
            while (have == need) {
                if (r-l+1 < res_len) {
                    res[0] = l;
                    res[1] = r;
                    res_len = r-l+1;
                }
                sub_str_map[s[l]] -= 1;
                if (tmap.find(s[l]) != tmap.end() && sub_str_map[s[l]] < tmap[s[l]]) {
                    have--;
                }
                l++;
            }
        }
        if (res_len == s.size()+1) {
            return "";
        }
        return s.substr(res[0], res[1]-res[0]+1);
    }
};

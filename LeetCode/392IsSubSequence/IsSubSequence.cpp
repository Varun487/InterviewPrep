class Solution {
public:
    bool isSubsequence(string s, string t) {
        // Pointers -> Time: O(n), Space:O(1)
        int i = 0, j = 0, n = s.size(), m = t.size();
        while ((i < n) && (j < m)) {
            if (s[i] == t[j]) {
                i += 1;
            }
            j += 1;
        }
        if (i == n) {
            return true;
        }
        return false;
    }
};

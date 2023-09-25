class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Sliding window -> Time:O(n), Space:O(n)
        vector<int> s1Count(26,0), s2Count(26,0);
        int index, l = 0, matches = 0, n = s1.size(), m = s2.size();
        if (m < n) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            s1Count[s1[i]-'a']++;
            s2Count[s2[i]-'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (s1Count[i] == s2Count[i]) {
                matches++;
            }
        }
        for (int r = n; r < m; r++) {
            if (matches == 26) {
                return true;
            }
            index = s2[r] - 'a';
            s2Count[index]++;
            if (s2Count[index] == s1Count[index]) matches++;
            else if (s2Count[index] == s1Count[index]+1) matches--;
            index = s2[l] - 'a';
            s2Count[index]--;
            if (s2Count[index] == s1Count[index]) matches++;
            else if (s2Count[index] == s1Count[index]-1) matches--;
            l++;
        }
        return (matches == 26);
    }
};

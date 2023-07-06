class Solution {
public:
    string convert(string s, int numRows) {
        // String manipulation -> Time:O(n), Space:O(n)
        if (numRows == 1) {
            return s;
        }
        string ans = "";
        int increment = 2*(numRows - 1);
        for (int r = 0; r < numRows; r++) {
            for (int i = r; i < s.size(); i += increment) {
                ans += s[i];
                if (r > 0 && r < numRows - 1 && i + increment - 2*r < s.size()) {
                    ans += s[i + increment - 2*r];
                }
            }
        }
        return ans;
    }
};

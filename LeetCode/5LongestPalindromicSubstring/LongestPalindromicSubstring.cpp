class Solution {
public:
    string longestPalindrome(string s) {
        // 2D DP -> Time:O(n^2), Space:O(n^2)
        vector<vector<int>> dp;
        for (int i = 0; i < s.size(); i++) {
            vector<int> temp(s.size(), 0);
            dp.push_back(temp);
        }
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < s.size()-i; j++) {
                cout << j << j+i << endl;
                if (i == 0) {
                    dp[j][j+i] = 1;
                }
                else if (i == 1) {
                    dp[j][j+i] = s[j] == s[j+i] ? 1 : 0;
                }
                else if (s[j] == s[j+i] && dp[j+1][j+i-1] == 1) {
                    dp[j][j+i] = 1;
                }
            }
        }
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j][s.size()-i+j]) {
                    return s.substr(j, s.size()-i+1);
                }
            }
        }
        return s.substr(0, 1);
    }
};

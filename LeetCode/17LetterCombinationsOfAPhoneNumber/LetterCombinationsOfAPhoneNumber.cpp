class Solution {
public:
    void backtrack(string &digits, vector<string> &ans, map<char,string> &m, int currentDigit, string curr) {
        if (curr.size() == digits.size()) {
            ans.push_back(curr);
            return;
        }
        for (int i = 0; i < m[digits[currentDigit]].size(); i++) {
            backtrack(digits, ans, m, currentDigit+1, curr+m[digits[currentDigit]][i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        // Backtracking -> Time:O(n*4^n), Space:O(n*4^n)
        map<char,string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        vector<string> ans;
        if (digits.size() != 0) {
            backtrack(digits, ans, m, 0, "");
        }
        return ans;
    }
};

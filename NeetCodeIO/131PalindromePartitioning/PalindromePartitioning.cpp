class Solution {
public:

    vector<vector<string>> ans;
    vector<string> part;

    bool isPalin(string s) {
        for (int i = 0; i < s.size()/2; i++) {
            if (s[i] != s[s.size()-1-i]) {
                return false;
            }
        }
        return true;
    }

    void dfs(int i, string s) {
        if (i >= s.size()) {
            ans.push_back(part);
            return;
        }
        for (int j = i; j < s.size(); j++) {
            if (isPalin(s.substr(i, j-i+1))) {
                part.push_back(s.substr(i, j-i+1));
                dfs(j+1, s);
                part.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        // Backtracking -> Time:O(2^n), Space:O(n)
        dfs(0, s);
        return ans;
    }
};

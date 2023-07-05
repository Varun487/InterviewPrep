class Solution {
public:
    string reverseWords(string s) {
        // Single pass -> Time:O(n), Space:O(n) n=len(s)
        int j, i = 0;
        int n = s.size();
        string ans = "";
        while (i < n) {
            while (i < n && s[i] == ' ') {
                i++;
            }
            if (i >= n) {
                break;
            }
            j = i+1;
            while (j < n && s[j] != ' ') {
                j++;
            }
            if (ans == "") {
                ans = s.substr(i, j-i);
            }
            else {
                ans = s.substr(i, j-i) + ' ' + ans;
            }
            cout << ans << endl;
            i = j + 1;
        }
        return ans;
    }
};
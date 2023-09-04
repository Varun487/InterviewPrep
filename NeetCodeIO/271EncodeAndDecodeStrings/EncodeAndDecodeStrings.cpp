class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        string ans = "";
        for (int i = 0; i < strs.size(); i++) {
            ans += to_string(strs[i].size()) + "#" + strs[i];
        }
        return ans;
    }

    /*
     * @param str: A string
     * @return: decodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        int i = 0;
        vector<string> ans;
        while (i < str.size()) {
            int j = i;
            while (str[j] != '#') {
                j++;
            }
            int length = stoi(str.substr(i, j-i+1));
            ans.push_back(str.substr(j, length));
            i = j + 1 + length;
        }
        return ans;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Brute force -> Time:O(nm), Space:O(1)
        string longest_common_prefix = "";
        for (int i = 0; i  < strs[0].size(); i++) {
            for (int j = 0; j < strs.size();  j++) {
                if (i == strs[j].size() || strs[j][i] != strs[0][i]) {
                    return longest_common_prefix;
                }
            }
            longest_common_prefix += strs[0][i];
        }
        return longest_common_prefix;
    }
};

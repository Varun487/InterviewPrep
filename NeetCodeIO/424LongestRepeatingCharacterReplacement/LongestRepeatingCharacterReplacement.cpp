class Solution {
public:
    int getMax(vector<int> count) {
        int ans = count[0];
        for (int i = 1; i < count.size(); i++) {
            ans = max(ans, count[i]);
        }
        return ans;
    }
    int characterReplacement(string s, int k) {
        // Sliding window -> Time:O(n), Space:O(1)
        int ans = 0, l = 0;
        vector<int> count(26, 0);
        for (int r = 0; r < s.size(); r++) {
            count[s[r] - 'A']++;
            while (r-l+1 - getMax(count) > k) {
                count[s[l] - 'A']--;
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};

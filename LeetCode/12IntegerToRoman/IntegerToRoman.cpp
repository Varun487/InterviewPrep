class Solution {
public:
    string intToRoman(int num) {
        // Single pass -> Time:O(n), Space:O(1)
        vector<int> int_vect {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> char_vect {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string ans = "";
        int count;
        for (int i = 0; i < int_vect.size(); i++) {
            count = num / int_vect[i];
            for (int j = 0; j < count; j++) {
                ans += char_vect[i];
            }
            num %= int_vect[i];
        }
        return ans;
    }
};
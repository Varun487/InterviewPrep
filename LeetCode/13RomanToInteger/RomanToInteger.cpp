class Solution {
public:
    int romanToInt(string s) {
        // Linear solution -> Time:O(n), Space:O(1)
        std::map<char, int> roman_to_int_map;
        roman_to_int_map['I'] = 1;
        roman_to_int_map['V'] = 5;
        roman_to_int_map['X'] = 10;
        roman_to_int_map['L'] = 50;
        roman_to_int_map['C'] = 100;
        roman_to_int_map['D'] = 500;
        roman_to_int_map['M'] = 1000;
        int i = 0;
        int int_sum = 0;
        while (i < s.size()-1) {
            if (roman_to_int_map[s[i]] < roman_to_int_map[s[i+1]]) {
                int_sum -= roman_to_int_map[s[i]];
            }
            else {
                int_sum += roman_to_int_map[s[i]];
            }
            i++;
        }
        int_sum += roman_to_int_map[s[i]];
        return int_sum;        
    }
};

class Solution {
public:
    bool isValid(string s) {
        // Stack -> Time:O(n), Space:O(1)
        stack<char> char_stack;
        map<char, char> char_map;
        char_map[']'] = '[';
        char_map[')'] = '(';
        char_map['}'] = '{';
        for (int i = 0; i < s.size(); i++) {
            if (char_map.find(s[i]) == char_map.end()) {
                char_stack.push(s[i]);
            }
            else if (!char_stack.empty() && char_stack.top() == char_map[s[i]]) {
                char_stack.pop();
            }
            else {
                return false;
            }
        }
        if (char_stack.empty()) {
            return true;
        }
        return false;
    }
};

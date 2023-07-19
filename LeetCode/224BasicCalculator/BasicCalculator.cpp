class Solution {
public:
    int calculate(string s) {
        // Single pass -> Time:O(n), Space:O(1)
        int curr = 0, sign = 1, output = 0;
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                curr = curr*10 + (s[i]-'0');
            }
            else if (s[i] == '+' || s[i] == '-') {
                output += curr*sign;
                curr = 0;
                if (s[i] == '+') {
                    sign = 1;
                }
                else {
                    sign = -1;
                }
            }
            else if (s[i] == '(') {
                st.push(output);
                st.push(sign);
                output = 0;
                sign = 1;
            }
            else if (s[i] == ')') {
                output += curr*sign;
                output *= st.top();
                st.pop();
                output += st.top();
                st.pop();
                curr = 0;
            }
        }
        return output + curr*sign;
    }
};

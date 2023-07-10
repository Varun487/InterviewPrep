class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // Stack -> Time:O(n), Space:O(n)
        vector<int> s;
        string plus = "+";
        string minus = "-";
        string division = "/";
        string multiplication = "*";
        int a, b;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == plus) {
                a = s[s.size()-2];
                b = s[s.size()-1];
                s.pop_back();
                s.pop_back();
                s.push_back(a + b);
            }
            else if (tokens[i] == minus) {
                a = s[s.size()-2];
                b = s[s.size()-1];
                s.pop_back();
                s.pop_back();
                s.push_back(a - b);
            }
            else if (tokens[i] == multiplication) {
                a = s[s.size()-2];
                b = s[s.size()-1];
                s.pop_back();
                s.pop_back();
                s.push_back(a * b);
            }
            else if (tokens[i] == division) {
                a = s[s.size()-2];
                b = s[s.size()-1];
                s.pop_back();
                s.pop_back();
                s.push_back(a / b);
            }
            else {
                s.push_back(stoi(tokens[i]));
            }
        }
        return s[0];
    }
};

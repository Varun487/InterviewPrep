class Solution {
public:
    string simplifyPath(string path) {
        // Stack -> Time:O(n), Space:O(n)
        stack<string> s;
        path = path + '/';
        string curr = "";
        string ans = "";
        for (int i  = 0; i < path.size(); i++) {
            if (path[i] == '/') {
                if (curr == "..") {
                    if (!s.empty()) {
                        s.pop();
                    }
                }
                else if (curr != "." && curr != "") {
                    s.push(curr);
                }
                curr = "";
            }
            else {
                curr += path[i];
            }
        }
        while (!s.empty()) {
            if (ans == "") {
                ans += s.top();
            }
            else {
                ans = s.top() + '/' + ans;
            }
            s.pop();
        }
        ans = '/' + ans;
        return ans;
    }
};

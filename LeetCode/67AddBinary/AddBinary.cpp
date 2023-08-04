class Solution {
public:
    string addBinary(string a, string b) {
        // Bit -> Time:O(n), Space:O(n)
        string smaller = a;
        string bigger = b;
        string ans = "";
        int digit1, digit2, sum, carry = 0;
        if (a.size() > b.size()) {
            bigger = a;
            smaller = b;
        }
        for (int i = 0; i < smaller.size(); i++) {
            digit1 = bigger[bigger.size()-i-1]-'0';
            digit2 = smaller[smaller.size()-i-1]-'0';
            sum = digit1 + digit2 + carry;
            if (sum > 1) {
                carry = 1;
                sum -= 2;
            }
            else {
                carry = 0;
            }
            ans = to_string(sum) + ans;
        }
        for (int i = 0; i < bigger.size() - smaller.size(); i++) {
            sum = bigger[bigger.size() - smaller.size() - i - 1]-'0' + carry;
            if (sum > 1) {
                carry = 1;
                sum -= 2;
            }
            else {
                carry = 0;
            }
            ans = to_string(sum) + ans;
        }
        if (carry) {
            ans = to_string(1) + ans;
        }
        return ans;
    }
};

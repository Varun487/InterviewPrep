class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // Single Pass -> Time:O(n), Space:O(1)
        int sum, carry = 0;
        for (int i = digits.size()-1; i > -1; i--) {
            sum = digits[i];
            if (i == digits.size()-1) {
                sum++;
            }
            sum += carry;
            digits[i] = sum%10;
            carry = sum/10;
        }
        if (carry) {
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};

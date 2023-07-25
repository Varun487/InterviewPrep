class Solution {
public:
    unsigned long reverseNum(int x) {
        unsigned long num = 0;
        int digit;
        while (x) {
            digit = x%10;
            num = num*10 + digit;
            x /= 10;
        }
        return num;
    }
    bool isPalindrome(int x) {
        // Optimized and clean by computing the reversed number
        // Time:O(n), Space:O(1)
        if (x < 0) {
            return false;
        }
        return x == reverseNum(x);

        // // Single Pass, constant memory -> Time:O(n), Space:O(1)
        // if (x < 0) {
        //     return false;
        // }
        // long div = 1;
        // while (x >= 10*div) {
        //     div *= 10;
        // }
        // while (x) {
        //     if (x%10 != x/div) {
        //         return false;
        //     }
        //     x = (x%div)/10;
        //     div /= 100;
        // }
        // return true;

        // // Single Pass -> Time:O(n), Space:O(n) n=NumOfDigits
        // if (x < 0) {
        //     return false;
        // }
        // vector<int> palin;
        // while (x) {
        //     palin.push_back(x%10);
        //     x = x/10;
        // }
        // for (int i = 0; i < palin.size()/2; i++) {
        //     if (palin[i] != palin[palin.size()-1-i]) {
        //         return false;
        //     }
        // }
        // return true;
    }
};

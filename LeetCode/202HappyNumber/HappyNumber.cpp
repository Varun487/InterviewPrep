class Solution {
public:
    bool isHappy(int n) {
        // Run Till Cycle -> Time:O(n), Space:O(n)
        set<int> seen_nums;
        int sum;
        while (seen_nums.find(n) == seen_nums.end()) {
            seen_nums.insert(n);
            sum = 0;
            while (n != 0) {
                sum += (n%10)*(n%10);
                n = n/10;
            }
            n = sum;
        }
        if (n == 1) {
            return true;
        }
        return false;
    }
};
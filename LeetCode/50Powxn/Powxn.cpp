class Solution {
public:
    // Divide and conquer -> Time:O(log(n)), Space:O(1)
    double helper(double x, int n) {
        double res;
        if (x == 0) return 0;
        if (n == 0) return 1;
        res = helper(x, n/2);
        res *= res;
        if (n%2) {
            return x*res;
        }
        return res;
    }
    double myPow(double x, int n) {
        double res;
        res = helper(x, abs(n));
        if (n>=0) {
            return res;
        }
        return 1/res;
    }
};

class Solution {
public:
    int mySqrt(int x) {
        // Binary Search -> Time:O(log(n)), Space:O(1)
        long mul, m, ans, l = 0, r = x;
        while (l <= r) {
            m = l + (r - l)/ 2;
            mul = m*m;
            if (mul > x) {
                r = m - 1;
            }
            else if (mul < x) {
                l = m + 1;
                ans = m;
            }
            else {
                return m;
            }
        }
        return ans;
    }
};

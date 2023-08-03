class Solution {
public:
    int trailingZeroes(int n) {
        // Divide by 5 -> Time:O(logn), Space:O(1)
        int ans = 0, i = 1;
        while (n >= pow(5, i)) {
            ans += n/pow(5,i);
            i++;
        }
        return ans;
    }
};

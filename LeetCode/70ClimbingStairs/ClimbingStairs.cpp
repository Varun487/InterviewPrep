class Solution {
public:
    vector<int> store;
    int climbDP(int n) {
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            return 0;
        }
        if (store[n-1] != 0) {
            return store[n-1];
        }
        store[n-1] = climbDP(n-1) + climbDP(n-2);
        return store[n-1];
    }
    int climb(int n) {
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            return 0;
        }
        return climb(n-1) + climb(n-2);
    }
    int climbStairs(int n) {
        // Fibonacci series -> Time:O(n), Space:O(1)
        int temp, one = 1, two = 1;
        for (int i = 0; i < n - 1; i++) {
            temp = one;
            one += two;
            two = temp;
        }
        return one;
        // // Dynamic programming -> Time:O(n), Space:O(n)
        // for (int i = 0; i < n; i++) {
        //     store.push_back(0);
        // }
        // return climbDP(n);
        // // Brute Force -> Time:O(2^n), Space:O(n)
        // return climb(n); // Time limit exceeded
    }
};

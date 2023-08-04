lass Solution {
public:
    int hammingWeight(uint32_t n) {
        // Bit Manipulation -> Time:O(1), Space:O(1)
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            ans += (n >> i) & 1;
        }
        return ans;
    }
};

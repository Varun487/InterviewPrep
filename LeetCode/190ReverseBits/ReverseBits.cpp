class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // Bit Manipulation -> Time:O(1), Space:O(1)
        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {
            uint32_t bit = (n >> i) & 1;
            res = res | (bit << (31-i));
        }
        return res;
    }
};

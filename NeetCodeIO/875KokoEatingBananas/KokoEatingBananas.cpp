class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Binary Search -> Time:O(n*log(max(piles))), Space:O(1)
        int ans, k, r = piles[0], l = 1;
        for (int i = 0; i < piles.size(); i++) {
            if (piles[i] > r) {
                r = piles[i];
            }
        }
        double hours;
        ans = r;
        while (l <= r) {
            k = (l+r) / 2;
            hours = 0;
            for (int i = 0; i < piles.size(); i++) {
                hours += ceil(double(piles[i]) / k);
            }
            if (hours <= h) {
                r = k - 1;
                ans = min(ans, k);
            }
            else {
                l = k + 1;
            }
        }
        return ans;
    }
};

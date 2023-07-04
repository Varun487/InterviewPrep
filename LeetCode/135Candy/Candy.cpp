class Solution {
public:
    int candy(vector<int>& ratings) {
        // Time:O(n), Space:O(1)
        int n = ratings.size(), candies = 0;
        std::vector<int> l2r(n, 1);
        std::vector<int> r2l(n, 1);
        for (int i = 0; i < n; i++) {
            if (i > 0 && ratings[i] > ratings[i-1]) {
                l2r[i] = l2r[i-1] + 1;
            }
        }
        for (int i = n-2; i > -1; i--) {
            if (i > -1 && ratings[i] > ratings[i+1]) {
                r2l[i] = r2l[i+1] + 1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (l2r[i] > r2l[i]) {
                candies += l2r[i];
            }
            else {
                candies += r2l[i];
            }
        }
        return candies;
    }
};

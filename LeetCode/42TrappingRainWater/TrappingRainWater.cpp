class Solution {
public:
    int trap(vector<int>& height) {
        // Constant space -> Time:O(n), Space:O(1)
        if (height.size() < 3) {
            return 0;
        }
        int ans = 0, l = 0, r = height.size()-1, maxl = height[l], maxr = height[r];
        while (l < r) {
            if (maxl <= maxr) {
                l++;
                maxl = max(height[l], maxl);
                ans += maxl - height[l];
            }
            else {
                r--;
                maxr = max(height[r], maxr);
                ans += maxr - height[r];
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        // 2 pointers -> Time:O(n), Space:O(1)
        int water, ans = 0, l = 0, r = height.size()-1;
        while (l < r) {
            water = (r-l)*min(height[l], height[r]);
            if (water > ans) {
                ans = water;
            }
            if (height[l] < height[r]) {
                l++;
            }
            else {
                r--;
            }
        }
        return ans;
    }
};

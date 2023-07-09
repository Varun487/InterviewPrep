class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Reduce to 2Sum by sorting -> Time:O(n^2), Space:O(nC3)
        int l, r, threesum;
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp(3, 0);
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            l = i + 1;
            r = nums.size()-1;
            while (l < r) {
                threesum = nums[i] + nums[l] + nums[r];
                if (threesum > 0) {
                    r--;
                }
                else if (threesum < 0) {
                    l++;
                }
                else {
                    temp[0] = nums[i];
                    temp[1] = nums[l];
                    temp[2] = nums[r];
                    ans.push_back(temp);
                    l++;
                    while (l < r && nums[l] == nums[l-1]) {
                        l++;
                    }
                }
            }
        }
        return ans;
    }
};

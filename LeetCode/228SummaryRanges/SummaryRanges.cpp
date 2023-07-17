class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        // Single pass -> Time:O(n), Space:O(n)
        vector<string> ans;
        int i = 0, start, end;
        while (i < nums.size()) {
            start = i;
            end = i;
            while (i+1 < nums.size() && int(long(nums[i+1]) - long(nums[i])) == 1) {
                end++;
                i++;
            }
            if (start == end) {
                ans.push_back(to_string(nums[start]));
            }
            else {
                ans.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
            }
            i++;
        }
        return ans;
    }
};

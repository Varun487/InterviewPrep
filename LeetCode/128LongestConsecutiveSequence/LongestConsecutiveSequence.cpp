class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // HashSet -> Time:O(n), Space:O(n)
        set<int> s(nums.begin(), nums.end());
        int ans = 0, curr_seq, curr_num;
        for (int i = 0; i < nums.size(); i++) {
            curr_num = nums[i];
            curr_seq = 0;
            if (s.find(curr_num-1) == s.end()) {
                curr_seq++;
                while (s.find(curr_num+1) != s.end()) {
                    curr_seq++;
                    curr_num++;
                }
                if (curr_seq > ans) {
                    ans = curr_seq;
                }
            }
        }
        return ans;
    }
};

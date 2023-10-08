class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 2 pointers -> Time:O(n), Space:O(n)
        vector<int> ans;
        deque<int> q;
        int l = 0, r = 0;
        while (r < nums.size()) {
            while (!q.empty() && nums[q[q.size()-1]] < nums[r]) {
                q.pop_back();
            }
            q.push_back(r);
            if (l > q[0]) {
                q.pop_front();
            }
            if (r + 1 >= k) {
                ans.push_back(nums[q[0]]);
                l++;
            }
            r++;
        }
        return ans;
    }
};

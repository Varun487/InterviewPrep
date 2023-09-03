class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Bucket Sort -> Time:O(n), Space:O(n)
        map<int,int> m;
        vector<vector<int>> freq;
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i <= n; i++) {
            vector<int> temp;
            freq.push_back(temp);
        }
        for (int i = 0; i < n; i++) {
            m[nums[i]]++;
        }
        for (auto i:m) {
            freq[i.second].push_back(i.first);
        }
        for (int i = n; i > 0; i--) {
            for (int j = 0; j < freq[i].size(); j++) {
                ans.push_back(freq[i][j]);
                if (ans.size() == k) {
                    return ans;
                }
            }
        }
        return ans;
    }
};

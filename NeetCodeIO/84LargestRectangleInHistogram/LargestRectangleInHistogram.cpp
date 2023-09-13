class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Stack -> Time:O(n), Space:O(1)
        stack<pair<int,int>> s;
        int area, start, ans = 0;
        pair<int,int> tempPair;
        for (int i = 0; i < heights.size(); i++) {
            start = i;
            while (!s.empty() && s.top().second > heights[i]) {
                tempPair = s.top();
                s.pop();
                ans = max(ans, tempPair.second * (i - tempPair.first));
                start = tempPair.first;
            }
            tempPair.first = start;
            tempPair.second = heights[i];
            s.push(tempPair);
        }
        while (!s.empty()) {
            tempPair = s.top();
            s.pop();
            area = tempPair.second * (heights.size() - tempPair.first);
            ans = max(ans, area);
        }
        return ans;
    }
};

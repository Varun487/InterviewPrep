lass Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // Stack -> Time:O(n), Space:O(n)
        stack<pair<int,int>> st;
        vector<int> ans(temperatures.size(), 0);
        pair<int,int> tempPair;
        for (int i = 0; i < temperatures.size(); i++) {
            while (!st.empty() && temperatures[i] > st.top().first) {
                tempPair = st.top();
                st.pop();
                ans[tempPair.second] = i - tempPair.second;
            }
            tempPair.first = temperatures[i];
            tempPair.second = i;
            st.push(tempPair);
        }
        return ans;
    }
};

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // Stack -> Time:O(n*log(n)), Space:O(n)
        vector<pair<int,int>> pairs;
        for (int i = 0; i < position.size(); i++) {
            pair<int,int> temp;
            temp.first = position[i];
            temp.second = speed[i];
            pairs.push_back(temp);
        }
        sort(pairs.begin(), pairs.end(), greater<pair<int,int>>());
        stack<double> s;
        double calc;
        for (int i = 0; i < pairs.size(); i++) {
            calc = double((target - pairs[i].first)) / pairs[i].second;
            if (s.empty() || calc > s.top()) {
                s.push(calc);
            }
        }
        return s.size();
    }
};

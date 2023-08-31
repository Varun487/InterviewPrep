class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // 2 heaps -> Time:O(k*log(n)), Space:O(n)
        vector<int> maxProfit;
        vector<pair<int,int>> minCapital;
        int c, p;
        for (int i = 0; i < profits.size(); i++) {
            pair<int,int> tempPair;
            tempPair.first = -1*capital[i];
            tempPair.second = profits[i];
            minCapital.push_back(tempPair);
        }
        make_heap(minCapital.begin(), minCapital.end());
        for (int i = 0; i < k; i++) {
            while (minCapital.size() != 0 && -1*minCapital.front().first <= w) {
                p = minCapital.front().second;
                pop_heap(minCapital.begin(), minCapital.end()); minCapital.pop_back();
                maxProfit.push_back(p); push_heap(maxProfit.begin(), maxProfit.end());
            }
            if (maxProfit.size() == 0) {
                break;
            }
            w += maxProfit.front();
            pop_heap(maxProfit.begin(), maxProfit.end()); maxProfit.pop_back();
        }
        return w;
    }
};

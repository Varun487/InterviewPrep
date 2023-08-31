class Solution {
public:
    int hIndex(vector<int>& citations) {
        // Merge Sort, then find h index -> Time: O(nlogn), Space: O(1)
        sort(citations.begin(), citations.end());
        int i = 1, n = citations.size();
        while (i <= n) {
            if (citations[n-i] < i) {
                break;
            }
            i++;
        }
        return i - 1;
    }
};

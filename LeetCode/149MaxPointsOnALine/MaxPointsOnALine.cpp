class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        // Compute slope -> Time:O(n^2), Space:O(n)
        map<double,int> slopeCount;
        double num, den, slope;
        int ans = 1;
        vector<int> currentPoint, nextPoint;
        for (int i = 0; i < points.size(); i++) {
            slopeCount.clear();
            currentPoint = points[i];
            for (int j = i + 1; j < points.size(); j++) {
                nextPoint = points[j];
                num = currentPoint[1] - nextPoint[1];
                den = currentPoint[0] - nextPoint[0];
                if (den == 0) {
                    slope = DBL_MAX;
                }
                else {
                    slope = num/den;
                }
                slopeCount[slope]++;
                ans = max(slopeCount[slope] + 1, ans);
            }
        }
        return ans;
    }
};

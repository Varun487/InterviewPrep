lass Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // Kadane's algorithm -> Time:O(n), Space:O(1)
        int globalMax = nums[0], globalMin = nums[0], total = 0, currMax = 0, currMin = 0;
        for (int i = 0; i < nums.size(); i++) {
            currMax = max(currMax + nums[i], nums[i]);
            currMin = min(currMin + nums[i], nums[i]);
            total += nums[i];
            globalMax = max(globalMax, currMax);
            globalMin = min(globalMin, currMin);
        }
        if (globalMax < 0) {
            return globalMax;
        }
        return max(globalMax, total - globalMin);
    }
};

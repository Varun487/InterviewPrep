class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Heap -> Time:O(n+klog(n)), Space:O(n)
        make_heap(nums.begin(), nums.end());
        for (int i = 0; i < k-1; i++) {
            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
        }
        return nums.front();
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // Reverse -> Time: O(n), Space:O(1)
        k = k%nums.size();
        int temp, l = 0, r = nums.size()-1;
        while (l < r) {
            temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            l++;
            r--;
        }
        l = 0;
        r = k-1;
        while (l < r) {
            temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            l++;
            r--;
        }
        l = k;
        r = nums.size()-1;
        while (l < r) {
            temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            l++;
            r--;
        }

        // // Temp array -> Time: O(n), Space:O(n)
        // int n = nums.size();
        // vector<int> new_nums(n);
        // for (int i = 0; i < n; i++) {
        //     new_nums[(i+k)%n] = nums[i];
        // }
        // for (int i = 0; i < n; i++) {
        //     nums[i] = new_nums[i];
        // }
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // 2 pointers -> Time:O(n), Space:O(1)
        int l = 0, r = numbers.size() - 1;
        vector<int> ans(2);
        while (numbers[l] + numbers[r] != target) {
            if (target - numbers[r] > numbers[l]) {
                l++;
            }
            else {
                r--;
            }
        }
        ans[0] = l+1;
        ans[1] = r+1;
        return ans;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Prefix & Postfix method: Time: O(n), Space: O(n)
        vector<int> prod(nums.size(), 1);
        int prefix = 1, postfix = 1;
        for(int i = 1; i < nums.size(); i++){
            prefix *= nums[i-1];
            prod[i] *= prefix;
        }
        for(int i = nums.size()-1; i > -1; i--){
            prod[i] *= postfix;
            postfix *= nums[i];
        }
        return prod;
    }
};
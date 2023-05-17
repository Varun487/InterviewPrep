class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Dictionary -> O(n)
        unordered_map<int, int> umap;
        vector<int> vect(2);
        int subtract;
        for (int i  = 0; i < nums.size(); i++) {
            subtract = target - nums[i];
            if (umap.count(subtract) != 0) {
                vect[0] = umap[subtract];
                vect[1] = i;
                return vect;
            }
            umap[nums[i]] = i;
        }
        return vect;

        // // Brute force -> O(n^2)
        // vector<int> vect(2);
        // for (int i = 0; i < nums.size()-1; i++) {
        //     for (int j = i+1; j < nums.size(); j++) {
        //         if (nums[i] + nums[j] == target){
        //             vect[0] = i;
        //             vect[1] = j;
        //             return vect;
        //         }
        //     }
        // }
        // return vect;
    }
};
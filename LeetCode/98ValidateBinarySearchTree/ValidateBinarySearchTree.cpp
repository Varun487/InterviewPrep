class Solution {
public:
    bool valid(TreeNode* root, long long left, long long right) {
        // DFS -> Time:O(n), Space:O(h)
        if (!root) {
            return true;
        }
        if (root->val > left && root->val < right) {
            return valid(root->left, left, root->val) && valid(root->right, root->val, right);
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return valid(root, LLONG_MIN, LLONG_MAX);
    }
};

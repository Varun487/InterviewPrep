class Solution {
public:
    int minDiff = INT_MAX;
    void inorder(TreeNode* root, TreeNode* &prev) {
        if (!root) {
            return;
        }
        inorder(root->left, prev);
        if (prev) {
            minDiff = min(minDiff, root->val - prev->val);
        }
        prev = root;
        inorder(root->right, prev);
    }
    int getMinimumDifference(TreeNode* root) {
        // Inorder -> Time:O(n), Space:O(h)
        TreeNode* prev = NULL;
        inorder(root, prev);
        return minDiff;
    }
};

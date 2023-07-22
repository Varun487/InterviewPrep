class Solution {
public:
    bool dfs(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) {
            return true;
        }
        else if (left == NULL || right == NULL) {
            return false;
        }
        return left->val == right->val && dfs(left->left, right->right) && dfs(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        // DFS -> Time:O(n), Space:O(h)
        if (root == NULL) {
            return true;
        }
        return dfs(root->left, root->right);
    }
};

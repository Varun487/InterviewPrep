class Solution {
public:
    int dfs(TreeNode* root, int sum) {
        if (root == NULL) {
            return 0;
        }
        sum = sum*10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            return sum;
        }
        return dfs(root->left, sum) + dfs(root->right, sum);
    }
    int sumNumbers(TreeNode* root) {
        // DFS -> Time:O(n), Space:O(h)
        return dfs(root, 0);
    }
};

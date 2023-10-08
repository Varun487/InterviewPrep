class Solution {
public:
    int ans = 0;
    int dfs(TreeNode* root) {
        if (!root) {
            return -1;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        ans = max(ans, left + right + 2);
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // DFS -> Time:O(n), Space:O(n)
        dfs(root);
        return ans;
    }
};

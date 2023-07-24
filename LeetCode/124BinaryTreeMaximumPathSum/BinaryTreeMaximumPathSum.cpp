class Solution {
public:
    int ans;
    int dfs(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftMax = max(dfs(root->left), 0);
        int rightMax = max(dfs(root->right), 0);
        ans = max(ans, root->val+leftMax+rightMax);
        return root->val + max(leftMax, rightMax);
    }
    int maxPathSum(TreeNode* root) {
        // DFS -> Time:O(n), Space:O(h)
        ans = root->val;
        dfs(root);
        return ans;
    }
};

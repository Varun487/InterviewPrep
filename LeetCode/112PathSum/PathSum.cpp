class Solution {
public:
    bool dfs(TreeNode* node, int sum, int target_sum) {
        // Inorder traversal -> Time:O(n), Space:O(h), n=numberOfNodes, h=heightOfTree
        if (node == NULL) {
            return false;
        }
        int curr_sum = sum + node->val;
        if (node->left == NULL && node->right == NULL) {
            return curr_sum == target_sum;
        }
        return dfs(node->left, curr_sum, target_sum) || dfs(node->right, curr_sum, target_sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, 0, targetSum);
    }
};

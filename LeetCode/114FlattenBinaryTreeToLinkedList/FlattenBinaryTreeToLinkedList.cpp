class Solution {
public:
    TreeNode* dfs(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode* leftTail = dfs(root->left);
        TreeNode* rightTail = dfs(root->right);
        if (leftTail) {
            leftTail->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        if (rightTail) {
            return rightTail;
        }
        else if (leftTail) {
            return leftTail;
        }
        return root;
    }
    void flatten(TreeNode* root) {
        // DFS -> Time:O(n), Space:O(h)
        dfs(root);
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // Inorder traversal -> Time:O(n), Space:O(1)
        if (root == NULL) {
            return 0;
        }
        return (1 + max(maxDepth(root->left), maxDepth(root->right)));
    }
};

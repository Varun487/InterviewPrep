class Solution {
public:
    int leftHeight(TreeNode* root) {
        if (root) {
            return 1 + leftHeight(root->left);
        }
        return 0;
    }
    int rightHeight(TreeNode* root) {
        if (root) {
            return 1 + rightHeight(root->right);
        }
        return 0;
    }
    int countNodes(TreeNode* root) {
        // Binary search on leaves -> Time:O(logn*logn), Space:O(h)
        int leftDepth = leftHeight(root);
        int rightDepth = rightHeight(root);
        if (leftDepth == rightDepth) {
            return pow(2, leftDepth) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);

        // // DFS -> Time:O(n), Space:O(h)
        // if (root) {
        //     return 1 + countNodes(root->left) + countNodes(root->right);
        // }
        // return 0;
    }
};

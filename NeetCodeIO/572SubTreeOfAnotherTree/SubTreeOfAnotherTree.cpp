class Solution {
public:
    bool sameTree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;
        if (root && subRoot && root->val == subRoot->val) {
            return sameTree(root->left, subRoot->left) && sameTree(root->right, subRoot->right);
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // DFS -> Time:O(n*m), Space:O(n*m)
        if (!subRoot) return true;
        if (!root) return false;
        if (sameTree(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

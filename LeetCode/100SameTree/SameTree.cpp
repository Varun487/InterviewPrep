class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Inorder traversal -> Time:O(n), Space:O(1)
        if (p == NULL && q == NULL) {
            return true;
        }
        else if (p != NULL && q != NULL) {
            if (p->val == q->val) {
                return true && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
            }
            return false;
        }
        return false;
    }
};